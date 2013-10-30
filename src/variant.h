/* 
 * File:   variant.h
 * Author: GOro
 *
 * Created on 2013. október 27., 18:55
 */

#ifndef VARIANT_H
#define	VARIANT_H

#include <string>
#include <ostream>
#include <istream>

namespace sandbox {
/*! A union like type to store exactly one vale of the intrinsic or string types */
class Variant {
private:
    std::string data;
    friend inline std::ostream& operator << (std::ostream& output, Variant const& variant);
public:
    Variant();
    Variant(double const value);
    Variant(float const value);
    Variant(int const value);
    Variant(char const* value);
    Variant(std::string const& value);
    inline double toDouble() const;
    inline float toFloat() const;
    inline int toInt() const;
    inline std::string toString() const;
};

Variant::Variant() {}

Variant::Variant(double const value) : data(std::to_string(value)) {}

Variant::Variant(float const value) : data(std::to_string(value)) {}

Variant::Variant(int const value) : data(std::to_string(value)) {}

Variant::Variant(char const* value) : data(value) {}

Variant::Variant(std::string const& value) : data(value) {}

inline double Variant::toDouble() const {
    return std::stod(data);
}

inline float Variant::toFloat() const {
    return std::stof(data);
}

inline int Variant::toInt() const {
    return std::stoi(data);
}

inline std::string Variant::toString() const {
    return data;
}

inline std::ostream& operator << (std::ostream& output, Variant const& variant) {
    output << variant.data;
    return output;
}

}

#endif	/* VARIANT_H */

