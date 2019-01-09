#include "FinancialOperationsManager.h"

void FinancialOperationsManager::addIncome() {
    Income income;
    system("cls");
    char choice;
    string date;
    choice = chooseTypeOfDateFromMenu();
    date = setTheDateOfTheFinancialOperation(choice);
    if (date == "0") {
        cout << "The date is incorrect.";
        system("pause");
        return;
    } else {
        income = addDetailsOfTheIncome(date);
        incomes.push_back(income);
        fileWithIncomes.addIncomeToFile(income);
        cout << "Income has been added." << endl;
    }
}

void FinancialOperationsManager::addExpense() {
    Expense expense;
    system("cls");
    char choice;
    string date;
    choice = chooseTypeOfDateFromMenu();
    date = setTheDateOfTheFinancialOperation(choice);
    if (date == "0") {
        cout << "The date is incorrect.";
        system("pause");
        return;
    } else {
        expense = addDetailsOfTheExpense(date);
        expenses.push_back(expense);
        fileWithExpenses.addExpenseToFile(expense);
        cout << "Expense has been added." << endl;
    }
}

char FinancialOperationsManager::chooseTypeOfDateFromMenu() {

    char choice;

    cout << ">>>> ADDING OPERATION <<<<" << endl;
    cout << "--------------------------" << endl;
    cout << "Choose from menu below:" << endl;
    cout << "1. Add operation with current date." << endl;
    cout << "2. Set date for the operation." << endl;
    choice = loadChar();

    return choice;
}

char FinancialOperationsManager::loadChar() {
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

Income FinancialOperationsManager::addDetailsOfTheIncome(string dateOfTheExpense) {
    Income income;
    string nameOfTheIncome;
    int amountOfIncome;

    income.setIncomeId(fileWithIncomes.getTheIdOfLastIncome() + 1);

    income.setUserId(loggedInUserId);

    income.setDate(dateOfTheExpense);

    cout << "Enter name of the income: ";
    nameOfTheIncome = loadText();
    income.setItem(nameOfTheIncome);

    cout << "Enter amount: ";
    cin >> amountOfIncome;
    income.setAmount(amountOfIncome);

    return income;
}

string FinancialOperationsManager::setTheDateOfTheFinancialOperation (char choice) {
    string date;
    switch (choice) {
    case '1':
        date = auxiliaryMethods.setCurrentDateOfTheOperation();
        return date;
        break;
    case '2':
        date = auxiliaryMethods.setUsersDateOfTheOperation();
        return date;
        break;
    }
}

Expense FinancialOperationsManager::addDetailsOfTheExpense(string dateOfTheExpense) {
    Expense expense;
    string nameOfTheExpense;
    int amountOfExpense;

    expense.setExpenseId(fileWithExpenses.getTheIdOfLastExpense() + 1);

    expense.setUserId(loggedInUserId);

    expense.setDate(dateOfTheExpense);

    cout << "Enter name of the expense: ";
    nameOfTheExpense = loadText();
    expense.setItem(nameOfTheExpense);

    cout << "Enter amount: ";
    cin >> amountOfExpense;
    expense.setAmount(amountOfExpense);

    return expense;
}

string FinancialOperationsManager::loadText() {
    string text;
    cin.sync();
    getline(cin, text);
    return text;
}
