#include "chromaaberration.h"
#include <boost/gil/extension/io/png_io.hpp>
#include <boost/gil/image.hpp>
#include <boost/gil/image_view.hpp>
#include <random>
#include <chrono>
#include <functional>
#include <vector>
#include <iostream>

template<typename ImageView>
inline void colorAberration(ImageView source, ImageView destination) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> red_distribution(2,8);
    std::uniform_int_distribution<int> green_distribution(1,6);
    std::uniform_int_distribution<int> blue_distribution(-8,-2);
    std::uniform_real_distribution<double> distribution(0.9, 1.0);
    auto red_dice = std::bind(red_distribution, generator);
    auto blue_dice = std::bind(blue_distribution, generator);
    auto green_dice = std::bind(green_distribution, generator);
    auto noise_fn = std::bind(distribution, generator);
    
    using namespace boost::gil;
    rgb8_view_t::x_iterator src_it, dest_r_it, dest_g_it, dest_b_it;
    //#pragma omp parallel for
    for (int y = 0; y < source.height(); ++y) {
        src_it = source.row_begin(y);
        dest_r_it = destination.row_begin(y) + red_dice();
        dest_g_it = destination.row_begin(y) + green_dice();
        dest_b_it = destination.row_begin(y) + blue_dice();
        
        double noise = 0.0;
        for (; src_it < source.row_end(y); ++src_it, ++dest_r_it, ++dest_g_it, ++dest_b_it)  {
            noise = noise_fn();
            if (dest_r_it > destination.row_begin(y) && dest_r_it < destination.row_end(y)) {
                dest_r_it[0][0] = y % 2 == 1 ? src_it[0][0] * noise : src_it[0][0] * 0.9 * noise;
            }
            if (dest_g_it > destination.row_begin(y) && dest_g_it < destination.row_end(y)) {
                dest_g_it[0][1] = y % 2 == 1 ? src_it[0][1] * noise : src_it[0][1] * 0.9 * noise;
            }
            if (dest_b_it > destination.row_begin(y) && dest_b_it < destination.row_end(y)) {
                dest_b_it[0][2] = y % 2 == 1 ? src_it[0][2] * noise : src_it[0][2] * 0.9 * noise;
            }
        }
    }
}

int main(int argc, char** argv) {
    using namespace boost::gil;
    rgb8_image_t image_in;
    // Load
    // TODO: exception handling
    png_read_image("gil-test.png", image_in);
    rgb8_image_t image_out(image_in.dimensions());
    rgb8_view_t image_in_view = view(image_in);
    rgb8_view_t image_out_view = view(image_out);
    fill_pixels(image_out_view, rgb8_pixel_t(0, 0, 0));
    using namespace std::chrono;
    
    high_resolution_clock::time_point start = high_resolution_clock::now();
    colorAberration(image_in_view, image_out_view);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    std::cout << (duration_cast<milliseconds>(end - start)).count() << "ms" << std::endl;
    // Save
    png_write_view("output.png", image_out_view);
    return 0;
}