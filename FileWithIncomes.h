#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"

class FileWithIncomes {
    const string nameOfTheFileWithIncomes;
    int idOfLastIncome;
    Income income;
    vector<Income> incomes;

public:
    FileWithIncomes(string NAMEOFTHEFILEWITHINCOMES) : nameOfTheFileWithIncomes(NAMEOFTHEFILEWITHINCOMES) {
        idOfLastIncome = 0;
    };
    vector <Income> loadIncomesOfLoggedInUserFromFile(int loggedInUserId);
    int getTheIdOfLastIncome();
    void addIncomeToFile(Income income);
};

#endif //FILEWITHINCOMES_H
