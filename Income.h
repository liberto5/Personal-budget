#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income {
    int incomeId;
    int userId;
    string date;
    string item;
    double amount;
    int dateAsUnixTime;

public:
    void setIncomeId (int newIncomeId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (double newAmount);
    void setDateAsUnixTime (int newDateAsUnixTime);

    int downloadIncomeId();
    int downloadUserId();
    string downloadDate();
    string downloadItem();
    double downloadAmount();
    int downloadDateAsUnixTime() const;
};

bool operator<(const Income &i1, const Income &i2);

#endif //INCOME_H
