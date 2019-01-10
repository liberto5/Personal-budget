#include <iostream>

#include "PersonalBudget.h"

using namespace std;

char chooseOptionFromMainMenu();
char chooseOptionFromUsersMenu();
char loadChar();

int main() {

    PersonalBudget personalBudget ("FileWithUsers.xml", "Incomes.xml", "Expenses.xml");

    char choice;

    while (true) {
        if (personalBudget.isUserLoggedIn() == false) {
            choice = chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.signUp();
                break;
            case '2':
                personalBudget.signIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in main menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = chooseOptionFromUsersMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showBalanceFromTheCurrentMonth();
                break;
            case '4':
                personalBudget.showBalanceFromThePreviousMonth();
                break;
            case '5':
                personalBudget.showBalanceFromPeriod();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logOut();
                break;
            }
        }
    }
    return 0;
}

char chooseOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "     >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Sign in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadChar();

    return choice;
}

char chooseOptionFromUsersMenu() {
    char choice;

    system("cls");
    cout << "             >>> USER'S MENU <<<" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show balance from current month" << endl;
    cout << "4. Show balance from previous month" << endl;
    cout << "5. Show balance from selected period of time" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadChar();

    return choice;
}

char loadChar() {
    string entry = "";
    char character  = {0};
    cin.sync();

    while (true) {
        getline(cin, entry);

        if (entry.length() == 1) {
            character = entry[0];
            break;
        }
        cout << "This is not a single character. Try again." << endl;
    }
    return character;
}
