#include "PersonalBudget.h"

void PersonalBudget::signUp()
{
    userManager.signUp();
}

void PersonalBudget::displayAllUsers()
{
    userManager.displayAllUsers();
}

void PersonalBudget::signIn()
{
    userManager.signIn();
}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}

void PersonalBudget::logOut()
{
    userManager.logOut();
}
