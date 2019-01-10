#include "PersonalBudget.h"

void PersonalBudget::signUp() {
    userManager.signUp();
}

void PersonalBudget::displayAllUsers() {
    userManager.displayAllUsers();
}

void PersonalBudget::signIn() {
    userManager.signIn();
    if (userManager.isUserLoggedIn()) {
        financialOperationsManager = new FinancialOperationsManager (nameOfTheFileWithIncomes, nameOfTheFileWithExpenses, userManager.downloadIdOfLoggedInUser());
    }
}

void PersonalBudget::changePassword() {
    userManager.changePassword();
}

void PersonalBudget::logOut() {
    userManager.logOut();
    delete financialOperationsManager;
    financialOperationsManager = NULL;
}

void PersonalBudget::addIncome() {
    if (userManager.isUserLoggedIn()) {
        financialOperationsManager->addIncome();
    } else {
        cout << "Log in to add income." << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense() {
    if (userManager.isUserLoggedIn()) {
        financialOperationsManager->addExpense();
    } else {
        cout << "Log in to add expense." << endl;
        system("pause");
    }
}

void PersonalBudget::showBalanceFromTheCurrentMonth(){
    if (userManager.isUserLoggedIn()) {
        financialOperationsManager->showBalanceFromTheCurrentMonth();
    } else {
        cout << "Log in to show user's balance." << endl;
        system("pause");
    }
}

void PersonalBudget::showBalanceFromThePreviousMonth(){
    if (userManager.isUserLoggedIn()) {
        financialOperationsManager->showBalanceFromThePreviousMonth();
    } else {
        cout << "Log in to show user's balance." << endl;
        system("pause");
    }
}
