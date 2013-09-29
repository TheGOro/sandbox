
#include "timetype.h"
#include <cmath>
#include <stdexcept>

sandbox::TimeType::TimeType(const int hour, const int minute) {
    // Range check
    if (hour > 23 || hour < 0) 
        throw std::range_error("hour not in range");
    if (minute > 59 || minute < 0) 
        throw std::range_error("minute not in range");
    this->hour = hour;
    this->minute = minute;
}

double sandbox::TimeType::getDegree() const {
    double hourDegree = (hour % 12) * 30;
    double minuteDegree = minute * 6;
    double degree = std::abs(hourDegree - minuteDegree);
    return degree > 180.0 ? degree - 180.0 : degree;
}
