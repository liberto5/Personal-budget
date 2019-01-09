#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income {
    int incomeId;
    int userId;
    string date;
    string item;
    int amount;

public:
    void setIncomeId (int newIncomeId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (int newAmount);

    int downloadIncomeId();
    int downloadUserId();
    string downloadDate();
    string downloadItem();
    int downloadAmount();
};

#endif //INCOME_H