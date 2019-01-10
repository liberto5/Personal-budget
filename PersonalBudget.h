#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "FinancialOperationsManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    FinancialOperationsManager *financialOperationsManager;
    const string nameOfTheFileWithIncomes;
    const string nameOfTheFileWithExpenses;

public:
    PersonalBudget (string nameOfFileWithUsers, string NAMEOFTHEFILEWITHINCOMES, string NAMEOFTHEFILEWITHEXPENSES) :
        userManager(nameOfFileWithUsers), nameOfTheFileWithIncomes (NAMEOFTHEFILEWITHINCOMES), nameOfTheFileWithExpenses (NAMEOFTHEFILEWITHEXPENSES) { };
    ~PersonalBudget() {
        delete financialOperationsManager;
    }
    void signUp();
    void displayAllUsers();
    void signIn();
    void changePassword();
    void logOut();
    void addIncome();
    void addExpense();
    void showBalanceFromTheCurrentMonth();
};

#endif //PERSONALBUDGET_H
