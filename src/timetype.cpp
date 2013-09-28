
#include "timetype.h"
#include <stdexcept>

TimeType::TimeType(const int hour, const int minute) {
    // Range check
    if (hour > 23 || hour < 0) 
        throw std::range_error("hour not in range");
    if (minute > 59 || minute < 0) 
        throw std::range_error("minute not in range");
    this->hour = hour;
    this->minute = minute;
}
double TimeType::getDegree() {
    int hourDegree(hour * 360 / 24);
}
