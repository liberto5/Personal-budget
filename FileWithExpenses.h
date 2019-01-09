#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include <vector>

#include "Expense.h"
#include "Markup.h"

class FileWithExpenses {
    const string nameOfTheFileWithExpenses;
    int idOfLastExpense;
    Expense expense;
    vector <Expense> expenses;

public:
    FileWithExpenses(string NAMEOFTHEFILEWITHEXPENSES) : nameOfTheFileWithExpenses(NAMEOFTHEFILEWITHEXPENSES) {
        idOfLastExpense = 0;
    };
    vector <Expense> loadExpensesOfLoggedInUserFromFile(int loggedInUserId);
    int getTheIdOfLastExpense();
    void addExpenseToFile(Expense expense);
};

#endif //FILEWITHEXPENSES_H
