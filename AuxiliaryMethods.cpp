#include "AuxiliaryMethods.h"

string AuxiliaryMethods::setCurrentDateOfTheOperation() {
    SYSTEMTIME localTime;
    GetLocalTime(&localTime);
    ostringstream year;
    year << localTime.wYear;
    string yearAsAPartOfString = year.str();
    ostringstream month;
    month << localTime.wMonth;
    string monthAsAPartOfString = month.str();
    if (monthAsAPartOfString.length() == 1)
        monthAsAPartOfString = "0" + monthAsAPartOfString;
    ostringstream day;
    day << localTime.wDay;
    string dayAsAPartOfString = day.str();
    if (dayAsAPartOfString.length() == 1)
        dayAsAPartOfString = "0" + dayAsAPartOfString;
    string currentDateAsAString = yearAsAPartOfString + "-" + monthAsAPartOfString + "-" + dayAsAPartOfString;

    return currentDateAsAString;
}



string AuxiliaryMethods::setUsersDateOfTheOperation() {
    cout << "Please enter the date (yyyy-mm-dd): ";
    string date;
    cin >> date;
    if (date.length() < 10) {
        date = "0";
        return date;
    }
    string year = date.substr( 0, 4);
    int yearAsAnInteger;
    istringstream strYear(year);
    strYear >> yearAsAnInteger;
    string month = date.substr( 5, 2);
    int monthAsAnInteger;
    istringstream strMonth(month);
    strMonth >> monthAsAnInteger;
    string day = date.substr( 8, 2);
    int dayAsAnInteger;
    istringstream strDay(day);
    strDay >> dayAsAnInteger;
    bool hasTheDateCorrectFormat = checkTheFormatOfTheDate(yearAsAnInteger, monthAsAnInteger, dayAsAnInteger);
    if (hasTheDateCorrectFormat == true) {
        return date;
    } else {
        date = "0";
        return date;
    }
}

bool AuxiliaryMethods::checkTheFormatOfTheDate(int yearAsAnInteger, int monthAsAnInteger, int dayAsAnInteger) {
    bool hasTheDateCorrectFormat = true;
    switch(monthAsAnInteger) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dayAsAnInteger < 1 || dayAsAnInteger > 31) {
            hasTheDateCorrectFormat = false;
            return hasTheDateCorrectFormat;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dayAsAnInteger < 1 || dayAsAnInteger > 30) {
            hasTheDateCorrectFormat = false;
            return hasTheDateCorrectFormat;
        }
        break;
    case 2:
        if (((yearAsAnInteger%4 == 0) && (yearAsAnInteger%100 != 0)) || (yearAsAnInteger%400 == 0)) {
            if (dayAsAnInteger < 1 || dayAsAnInteger > 29) {
                hasTheDateCorrectFormat = false;
                return hasTheDateCorrectFormat;
            }
        } else {
            if (dayAsAnInteger < 1 || dayAsAnInteger > 28) {
                hasTheDateCorrectFormat = false;
                return hasTheDateCorrectFormat;
            }
        }
        break;
    }
    if ((yearAsAnInteger < 2000) || (monthAsAnInteger < 1) || (monthAsAnInteger > 12)) {
        hasTheDateCorrectFormat = false;
        return hasTheDateCorrectFormat;
    }
    return hasTheDateCorrectFormat;
}


