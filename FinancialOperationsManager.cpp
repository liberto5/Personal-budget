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
        cout << "The date is incorrect." << endl;
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

void FinancialOperationsManager::showBalanceFromTheCurrentMonth() {
    vector <Income> incomesFromCurrentMonth;
    vector <Income> sortedIncomesFromCurrentMonth;
    system("cls");
    incomesFromCurrentMonth = loadIncomesOnlyFromCurrentMonth();
    sortedIncomesFromCurrentMonth = sortIncomesFromSelectedPeriodOfTime(incomesFromCurrentMonth);
    displayIncomesFromSelectedPeriodOfTime(sortedIncomesFromCurrentMonth);
    vector <Expense> expensesFromCurrentMonth;
    vector <Expense> sortedExpensesFromCurrentMonth;
    expensesFromCurrentMonth = loadExpensesOnlyFromCurrentMonth();
    sortedExpensesFromCurrentMonth = sortExpensesFromSelectedPeriodOfTime(expensesFromCurrentMonth);
    displayExpensesFromSelectedPeriodOfTime(sortedExpensesFromCurrentMonth);
}

vector <Income> FinancialOperationsManager::loadIncomesOnlyFromCurrentMonth() {
    Income income;
    vector <Income> incomesOnlyFromCurrentMonth;
    int currentYear = auxiliaryMethods.downloadCurrentYear();
    int currentMonth = auxiliaryMethods.downloadCurrentMonth();
    vector <Income>::iterator itr = incomes.begin();
    while (itr != incomes.end()) {
        string date = itr -> downloadDate();
        int yearFromUsersDate = auxiliaryMethods.downloadYearFromOperationDate(date);
        int monthFromUsersDate = auxiliaryMethods.downloadMonthFromOperationDate(date);
        if (yearFromUsersDate == currentYear && monthFromUsersDate == currentMonth) {
            income.setIncomeId(itr -> downloadIncomeId());
            income.setUserId(itr -> downloadUserId());
            income.setDate(itr -> downloadDate());
            income.setItem(itr -> downloadItem());
            income.setAmount(itr -> downloadAmount());
            income.setDateAsUnixTime(auxiliaryMethods.changeDateFormatForUnixTime(itr -> downloadDate()));
            incomesOnlyFromCurrentMonth.push_back(income);
        }
        itr++;
    }
    return incomesOnlyFromCurrentMonth;
}

vector <Expense> FinancialOperationsManager::loadExpensesOnlyFromCurrentMonth() {
    Expense expense;
    vector <Expense> expensesOnlyFromCurrentMonth;
    int currentYear = auxiliaryMethods.downloadCurrentYear();
    int currentMonth = auxiliaryMethods.downloadCurrentMonth();
    vector <Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end()) {
        string date = itr -> downloadDate();
        int yearFromUsersDate = auxiliaryMethods.downloadYearFromOperationDate(date);
        int monthFromUsersDate = auxiliaryMethods.downloadMonthFromOperationDate(date);
        if (yearFromUsersDate == currentYear && monthFromUsersDate == currentMonth) {
            expense.setExpenseId(itr -> downloadExpenseId());
            expense.setUserId(itr -> downloadUserId());
            expense.setDate(itr -> downloadDate());
            expense.setItem(itr -> downloadItem());
            expense.setAmount(itr -> downloadAmount());
            expense.setDateAsUnixTime(auxiliaryMethods.changeDateFormatForUnixTime(itr -> downloadDate()));
            expensesOnlyFromCurrentMonth.push_back(expense);
        }
        itr++;
    }
    return expensesOnlyFromCurrentMonth;
}

vector <Income> FinancialOperationsManager::sortIncomesFromSelectedPeriodOfTime(vector <Income> incomes)
{
    sort(incomes.begin(),incomes.end());
    return incomes;
}

vector <Expense> FinancialOperationsManager::sortExpensesFromSelectedPeriodOfTime(vector <Expense> expenses)
{
    sort(expenses.begin(),expenses.end());
    return expenses;
}

void FinancialOperationsManager::displayIncomesFromSelectedPeriodOfTime(vector <Income> incomes)
{
    cout << "----------INCOMES----------" << endl << endl;
    for(int i = 0; i < incomes.size(); i++) {
        cout<<incomes.at(i).downloadDate()<<" "<<incomes.at(i).downloadItem()<< " " <<incomes.at(i).downloadAmount()<< '\n';
    }
    cout << endl;
}

void FinancialOperationsManager::displayExpensesFromSelectedPeriodOfTime(vector <Expense> expenses)
{
    cout << "---------EXPENSES---------" << endl << endl;
    for(int i = 0; i < expenses.size(); i++) {
        cout<<expenses.at(i).downloadDate()<<" "<<expenses.at(i).downloadItem()<< " " <<expenses.at(i).downloadAmount()<< '\n';
    }
    system("pause");
}

bool operator<(const Income &i1, const Income &i2) {
    return i1.downloadDateAsUnixTime() < i2.downloadDateAsUnixTime();
}

bool operator<(const Expense &e1, const Expense &e2) {
    return e1.downloadDateAsUnixTime() < e2.downloadDateAsUnixTime();
}









