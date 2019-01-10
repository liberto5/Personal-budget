#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget ("FileWithUsers.xml", "Incomes.xml", "Expenses.xml");
    //personalBudget.displayAllUsers();
    //personalBudget.signUp();
    personalBudget.signIn();
    //personalBudget.changePassword();
    //personalBudget.logOut();
    //personalBudget.addIncome();
    //personalBudget.addExpense();
    //personalBudget.showBalanceFromTheCurrentMonth();
    personalBudget.showBalanceFromThePreviousMonth();
}
