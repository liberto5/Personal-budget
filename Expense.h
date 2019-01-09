#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense
{
    int expenseId;
    int userId;
    string date;
    string item;
    int amount;

public:
    void setExpenseId (int newExpenseId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (int newAmount);

    int downloadExpenseId();
    int downloadUserId();
    string downloadDate();
    string downloadItem();
    int downloadAmount();
};

#endif //EXPENSE_H
