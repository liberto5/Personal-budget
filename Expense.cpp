#include "Expense.h"

void Expense::setExpenseId(int newExpenseId) {
    if (newExpenseId >= 0)
        expenseId = newExpenseId;
}
void Expense::setUserId(int newUserId) {
    userId = newUserId;
}
void Expense::setDate (string newDate) {
    date = newDate;
}
void Expense::setItem (string newItem) {
    item = newItem;
}
void Expense::setAmount (double newAmount) {
    amount = newAmount;
}
void Expense::setDateAsUnixTime (int newDateAsUnixTime) {
    dateAsUnixTime = newDateAsUnixTime;
}

int Expense::downloadExpenseId() {
    return expenseId;
}
int Expense::downloadUserId() {
    return userId;
}
string Expense::downloadDate() {
    return date;
}
string Expense::downloadItem() {
    return item;
}
double Expense::downloadAmount() {
    return amount;
}
int Expense::downloadDateAsUnixTime() const {
    return dateAsUnixTime;
}
