#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <windows.h>
#include <ctime>

using namespace std;

class AuxiliaryMethods {

public:
    string setCurrentDateOfTheOperation();
    string setUsersDateOfTheOperation();
    bool checkTheFormatOfTheDate(int yearAsAnInteger, int monthAsAnInteger, int dayAsAnInteger);
    time_t changeDateFormatForUnixTime (string date);
    int downloadCurrentYear();
    int downloadCurrentMonth();
    int downloadYearFromOperationDate(string date);
    int downloadMonthFromOperationDate(string date);
};

#endif //AUXILIARYMETHODS_H
