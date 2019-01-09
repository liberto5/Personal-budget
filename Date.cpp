#include "Date.h"

void Date::setYear(int newYear) {
    if (newYear < 2000) {
        cout << "Out of range! Please enter data after 2000-01-01." << endl;
        system("pause");
    } else
        year = newYear;
}
void Date::setMonth(int newMonth) {
    month = newMonth;
}
void Date::setDay (int newDay) {
    day = newDay;
}
void Date::setHour(int newHour) {
    hour = newHour;
}
void Date::setMinute (int newMinute) {
    minute = newMinute;
}
void Date::setSecond (int newSecond) {
    second = newSecond;
}

int Date::downloadYear() {
    return year;
}
int Date::downloadMonth() {
    return month;
}
int Date::downloadDay() {
    return day;
}
int Date::downloadHour() {
    return hour;
}
int Date::downloadMinute() {
    return minute;
}
int Date::downloadSecond() {
    return second;
}
