#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget ("FileWithUsers.xml");
    personalBudget.displayAllUsers();
    //personalBudget.signUp();
    personalBudget.signIn();
}
