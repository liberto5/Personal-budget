#ifndef FINANCIALOPERATIONSMANAGER_H
#define FINANCIALOPERATIONSMANAGER_H
#include <iostream>
#include <windows.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

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
    double checkFormatAndChangeIntoDouble (string amount);
    string loadText();
    void showBalanceFromTheCurrentMonth();
    void showBalanceFromThePreviousMonth();
    void showBalanceFromPeriod();
    vector <Income> loadIncomesOnlyFromCurrentMonth();
    vector <Income> loadIncomesOnlyFromPreviousMonth();
    vector <Income> loadIncomesOnlyFromPeriod(string startDate, string endDate);
    vector <Expense> loadExpensesOnlyFromCurrentMonth();
    vector <Expense> loadExpensesOnlyFromPreviousMonth();
    vector <Expense> loadExpensesOnlyFromPeriod(string startDate, string endDate);
    vector <Income> sortIncomesFromSelectedPeriodOfTime(vector <Income> incomes);
    vector <Expense> sortExpensesFromSelectedPeriodOfTime(vector <Expense> expenses);
    void displayIncomesFromSelectedPeriodOfTime(vector <Income> incomes);
    void displayExpensesFromSelectedPeriodOfTime(vector <Expense> expenses);
    double sumIncomes (vector <Income> incomes);
    double sumExpenses (vector <Expense> expenses);
    double sumIncomesAndExpenses (double incomes, double expenses);
};

#endif //FINANCIALOPERATIONSMANAGER_H
