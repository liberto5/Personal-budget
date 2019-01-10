#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense {
    int expenseId;
    int userId;
    string date;
    string item;
    int amount;
    int dateAsUnixTime;

public:
    void setExpenseId (int newExpenseId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (int newAmount);
    void setDateAsUnixTime (int newDateAsUnixTime);

    int downloadExpenseId();
    int downloadUserId();
    string downloadDate();
    string downloadItem();
    int downloadAmount();
    int downloadDateAsUnixTime() const;
};

bool operator<(const Expense &e1, const Expense &e2);

#endif //EXPENSE_H
