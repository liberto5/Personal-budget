#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;

public:
    PersonalBudget (string nameOfFileWithUsers) : userManager(nameOfFileWithUsers) { };
    void signUp();
    void displayAllUsers();
    void signIn();
    void changePassword();
};

#endif //PERSONALBUDGET_H
