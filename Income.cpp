#include "Income.h"

void Income::setIncomeId(int newIncomeId) {
    if (newIncomeId >= 0)
        incomeId = newIncomeId;
}
void Income::setUserId(int newUserId) {
    userId = newUserId;
}
void Income::setDate (string newDate) {
    date = newDate;
}
void Income::setItem (string newItem) {
    item = newItem;
}
void Income::setAmount (int newAmount) {
    amount = newAmount;
}
void Income::setDateAsUnixTime (int newDateAsUnixTime) {
    dateAsUnixTime = newDateAsUnixTime;
}

int Income::downloadIncomeId() {
    return incomeId;
}
int Income::downloadUserId() {
    return userId;
}
string Income::downloadDate() {
    return date;
}
string Income::downloadItem() {
    return item;
}
int Income::downloadAmount() {
    return amount;
}
int Income::downloadDateAsUnixTime() const {
    return dateAsUnixTime;
}
