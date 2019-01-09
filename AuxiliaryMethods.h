#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

class AuxiliaryMethods {

public:
    string setCurrentDateOfTheOperation();
    string setUsersDateOfTheOperation();
    bool checkTheFormatOfTheDate(int yearAsAnInteger, int monthAsAnInteger, int dayAsAnInteger);

};

#endif //AUXILIARYMETHODS_H
