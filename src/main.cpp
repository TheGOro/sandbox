/* 
 * File:   main.cpp
 * Author: GOro
 *
 * Created on 2013. szeptember 29., 1:19
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <functional>
#include <algorithm>
#include "shed.h"
#include "pattern/singleton.h"
#include "quicksort.h"
#include "options.h"
#include "variant.h"

int main(int argc, char** argv) {
    std::string str("Reverse this!");
    sandbox::reverse(str);
    std::cout << str << std::endl;
    std::string str2("My little string!");
    sandbox::swapInRange(str2.begin() + 3, str2.begin() + 8);
    std::cout << str2 << std::endl;
    std::string str3("This is just a simple text.");
    sandbox::reverseWords(str3);
    std::cout << str3 << std::endl;
    std::cout << sandbox::pattern::Singleton::instance()->doMagic() << std::endl;
    std::cout << sandbox::pattern::Singleton::instance()->doMagic() << std::endl;
    std::cout << sandbox::pattern::Singleton::instance()->doMagic() << std::endl;
    int array[] = {4, 7, 22, 11, 6, 3, 8, 1, 9, 20};
    sandbox::quickSort(array, array + 9);
    sandbox::printOut(array, array + 9);
    int myints[] = {8, 32, 11, 45, 7, 1, 9, 66, 64, 90, 4, 5};
    std::vector<int> intVector = {62 , 11, 41, 32, 10, 65, 84, 14, 30, 96, 81, 17};
    sandbox::printOut(intVector.begin(), intVector.end() - 1);
    sandbox::quickSort(intVector);
    sandbox::printOut(intVector.begin(), intVector.end() - 1);
    
    // Playing with STL's random number generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1,10000000);
    auto dice = std::bind(distribution, generator);
    //int roll = distribution(generator);
    using namespace std::chrono;
    std::vector<int> numbers;
    std::vector<int> numbers2;
    int num(0);
    for (int i = 0 ; i < 1000000; ++i) {
        num = dice();
        numbers.push_back(num);
        numbers2.push_back(num);
        //std::cout << dice() << std::endl;
    }
    high_resolution_clock::time_point tp1 = high_resolution_clock::now();
    std::sort(numbers2.begin(), numbers2.end());
    high_resolution_clock::time_point tp2 = high_resolution_clock::now();
    sandbox::quickSort(numbers);
    high_resolution_clock::time_point tp3 = high_resolution_clock::now();
    microseconds sortTime = duration_cast<microseconds>(tp2 - tp1);
    microseconds quicksortTime = duration_cast<microseconds>(tp3 - tp2);
    
    std::cout << "std::sort time: " << sortTime.count() << std::endl;
    std::cout << "sandbox::quicksort time: " << quicksortTime.count() << std::endl;

    sandbox::Options options;
    options["Hello"] = "World";
    options["Key"] = "Value";
    options["Simple"] = "Complicated";
    options["Width"] = 1024;
    options["time"] = 4.78624;
    options["Clean"] = "Fancy";
    std::cout << options << std::endl;
    std::cout << "---" << std::endl;
    std::cout << options["Width"].toInt() << std::endl;
    std::cout << options["time"].toDouble() << std::endl;
    
    sandbox::Variant val = "14.22";
    std::cout << val.toDouble() << std::endl;
    std::cout << val.toInt() << std::endl;
    
    // Name generator
    return 0;
}