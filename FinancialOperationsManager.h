#ifndef FINANCIALOPERATIONSMANAGER_H
#define FINANCIALOPERATIONSMANAGER_H
#include <iostream>
#include <windows.h>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"

class FinancialOperationsManager
{
    const int loggedInUserId;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    AuxiliaryMethods auxiliaryMethods;

public:
    FinancialOperationsManager (string nameOfTheFileWithIncomes, string nameOfTheFileWithExpenses, int LOGGEDINUSERID) :
        fileWithIncomes(nameOfTheFileWithIncomes), fileWithExpenses(nameOfTheFileWithExpenses), loggedInUserId(LOGGEDINUSERID)
    {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(loggedInUserId);
        expenses = fileWithExpenses.loadExpensesOfLoggedInUserFromFile(loggedInUserId);
    };
    void addIncome();
    void addExpense();
    char chooseTypeOfDateFromMenu();
    char loadChar();
    string setTheDateOfTheFinancialOperation (char choice);
    Income addDetailsOfTheIncome(string dateOfTheExpense);
    Expense addDetailsOfTheExpense(string dateOfTheExpense);
    string loadText();
    void showBalanceFromTheCurrentMonth();
    vector <Income> loadIncomesOnlyFromCurrentMonth();
    vector <Expense> loadExpensesOnlyFromCurrentMonth();
    vector <Income> sortIncomesFromSelectedPeriodOfTime(vector <Income> incomes);
    vector <Expense> sortExpensesFromSelectedPeriodOfTime(vector <Expense> expenses);
    void displayIncomesFromSelectedPeriodOfTime(vector <Income> incomes);
    void displayExpensesFromSelectedPeriodOfTime(vector <Expense> expenses);
};

#endif //FINANCIALOPERATIONSMANAGER_H
