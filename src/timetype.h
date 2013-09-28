/* 
 * File:   timetype.h
 * Author: GOro
 *
 * Created on 2013. szeptember 29., 1:27
 */

#ifndef TIMETYPE_H
#define	TIMETYPE_H

class TimeType {
private:
    unsigned short int hour;
    unsigned short int minute;
public:
    TimeType(const int hour, const int minute);
    double getDegree() const;
};

#endif	/* TIMETYPE_H */

