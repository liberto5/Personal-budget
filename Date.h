#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Date
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

public:
    void setYear (int newYear);
    void setMonth (int newMonth);
    void setDay (int newDay);
    void setHour (int newHour);
    void setMinute (int newMinute);
    void setSecond (int newSecond);

    int downloadYear();
    int downloadMonth();
    int downloadDay();
    int downloadHour();
    int downloadMinute();
    int downloadSecond();
};

#endif //DATE_H
