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
        system("pause");
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
        system("pause");
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
    string amountOfIncome;

    income.setIncomeId(fileWithIncomes.getTheIdOfLastIncome() + 1);

    income.setUserId(loggedInUserId);

    income.setDate(dateOfTheExpense);

    cout << "Enter name of the income: ";
    nameOfTheIncome = loadText();
    income.setItem(nameOfTheIncome);

    cout << "Enter amount: ";
    cin >> amountOfIncome;
    double amountOfIncomeAsDouble = checkFormatAndChangeIntoDouble(amountOfIncome);
    income.setAmount(amountOfIncomeAsDouble);

    return income;
}

Expense FinancialOperationsManager::addDetailsOfTheExpense(string dateOfTheExpense) {
    Expense expense;
    string nameOfTheExpense;
    string amountOfExpense;

    expense.setExpenseId(fileWithExpenses.getTheIdOfLastExpense() + 1);

    expense.setUserId(loggedInUserId);

    expense.setDate(dateOfTheExpense);

    cout << "Enter name of the expense: ";
    nameOfTheExpense = loadText();
    expense.setItem(nameOfTheExpense);

    cout << "Enter amount: ";
    cin >> amountOfExpense;
    double amountOfExpenseAsDouble = checkFormatAndChangeIntoDouble(amountOfExpense);
    expense.setAmount(amountOfExpenseAsDouble);

    return expense;
}

double FinancialOperationsManager::checkFormatAndChangeIntoDouble (string amount)
{
    size_t i = amount.find(",");
    if (i != string::npos)
        amount.replace(i,1,".");
    stringstream ss;
    double amountAsADouble;
    ss << amount;
    ss >> amountAsADouble;

    return amountAsADouble;
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

string FinancialOperationsManager::loadText() {
    string text;
    cin.sync();
    getline(cin, text);
    return text;
}

void FinancialOperationsManager::showBalanceFromTheCurrentMonth() {
    cout << setprecision (2);
    cout << fixed;
    vector <Income> incomesFromCurrentMonth;
    vector <Income> sortedIncomesFromCurrentMonth;
    system("cls");
    incomesFromCurrentMonth = loadIncomesOnlyFromCurrentMonth();
    sortedIncomesFromCurrentMonth = sortIncomesFromSelectedPeriodOfTime(incomesFromCurrentMonth);
    displayIncomesFromSelectedPeriodOfTime(sortedIncomesFromCurrentMonth);
    double totalIncomes;
    totalIncomes = sumIncomes(incomesFromCurrentMonth);
    cout << "---------------------------" << endl;
    cout << "TOTAL INCOMES: " << totalIncomes << endl;
    vector <Expense> expensesFromCurrentMonth;
    vector <Expense> sortedExpensesFromCurrentMonth;
    expensesFromCurrentMonth = loadExpensesOnlyFromCurrentMonth();
    sortedExpensesFromCurrentMonth = sortExpensesFromSelectedPeriodOfTime(expensesFromCurrentMonth);
    displayExpensesFromSelectedPeriodOfTime(sortedExpensesFromCurrentMonth);
    double totalExpenses;
    totalExpenses = sumExpenses(expensesFromCurrentMonth);
    cout << "---------------------------" << endl;
    cout << "TOTAL EXPENSES: " << totalExpenses << endl << endl;
    double balanceFromCurrentMonth = sumIncomesAndExpenses(totalIncomes, totalExpenses);
    cout << "-------------------------------------" << endl;
    cout << "BALANCE FROM CURRENT MONTH: " << balanceFromCurrentMonth << endl;
    cout << "-------------------------------------" << endl;
}

void FinancialOperationsManager::showBalanceFromThePreviousMonth() {
    cout << setprecision (2);
    cout << fixed;
    vector <Income> incomesFromPreviousMonth;
    vector <Income> sortedIncomesFromPreviousMonth;
    system("cls");
    incomesFromPreviousMonth = loadIncomesOnlyFromPreviousMonth();
    sortedIncomesFromPreviousMonth = sortIncomesFromSelectedPeriodOfTime(incomesFromPreviousMonth);
    displayIncomesFromSelectedPeriodOfTime(sortedIncomesFromPreviousMonth);
    double totalIncomes;
    totalIncomes = sumIncomes(incomesFromPreviousMonth);
    cout << "---------------------------" << endl;
    cout << "TOTAL INCOMES: " << totalIncomes << endl;
    vector <Expense> expensesFromPreviousMonth;
    vector <Expense> sortedExpensesFromPreviousMonth;
    expensesFromPreviousMonth = loadExpensesOnlyFromPreviousMonth();
    sortedExpensesFromPreviousMonth = sortExpensesFromSelectedPeriodOfTime(expensesFromPreviousMonth);
    displayExpensesFromSelectedPeriodOfTime(sortedExpensesFromPreviousMonth);
    double totalExpenses;
    totalExpenses = sumExpenses(expensesFromPreviousMonth);
    cout << "---------------------------" << endl;
    cout << "TOTAL EXPENSES: " << totalExpenses << endl << endl;
    double balanceFromPreviousMonth = sumIncomesAndExpenses(totalIncomes, totalExpenses);
    cout << "-------------------------------------" << endl;
    cout << "BALANCE FROM PREVIOUS MONTH: " << balanceFromPreviousMonth << endl;
    cout << "-------------------------------------" << endl;
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

vector <Income> FinancialOperationsManager::loadIncomesOnlyFromPreviousMonth() {
    Income income;
    vector <Income> incomesOnlyFromPreviousMonth;
    int yearForPreviousMonth = auxiliaryMethods.downloadCurrentYear();
    int currentMonth = auxiliaryMethods.downloadCurrentMonth();
    int previousMonth;
    if (currentMonth == 1)
    {
        previousMonth = 12;
        yearForPreviousMonth--;
    }
    else
    {
        previousMonth = currentMonth - 1;
    }
    vector <Income>::iterator itr = incomes.begin();
    while (itr != incomes.end()) {
        string date = itr -> downloadDate();
        int yearFromUsersDate = auxiliaryMethods.downloadYearFromOperationDate(date);
        int monthFromUsersDate = auxiliaryMethods.downloadMonthFromOperationDate(date);
        if (yearFromUsersDate == yearForPreviousMonth && monthFromUsersDate == previousMonth) {
            income.setIncomeId(itr -> downloadIncomeId());
            income.setUserId(itr -> downloadUserId());
            income.setDate(itr -> downloadDate());
            income.setItem(itr -> downloadItem());
            income.setAmount(itr -> downloadAmount());
            income.setDateAsUnixTime(auxiliaryMethods.changeDateFormatForUnixTime(itr -> downloadDate()));
            incomesOnlyFromPreviousMonth.push_back(income);
        }
        itr++;
    }
    return incomesOnlyFromPreviousMonth;
}

vector <Expense> FinancialOperationsManager::loadExpensesOnlyFromPreviousMonth() {
    Expense expense;
    vector <Expense> expensesOnlyFromPreviousMonth;
    int yearForPreviousMonth = auxiliaryMethods.downloadCurrentYear();
    int currentMonth = auxiliaryMethods.downloadCurrentMonth();
    int previousMonth;
    if (currentMonth == 1)
    {
        previousMonth = 12;
        yearForPreviousMonth--;
    }
    else
    {
        previousMonth = currentMonth - 1;
    }
    vector <Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end()) {
        string date = itr -> downloadDate();
        int yearFromUsersDate = auxiliaryMethods.downloadYearFromOperationDate(date);
        int monthFromUsersDate = auxiliaryMethods.downloadMonthFromOperationDate(date);
        if (yearFromUsersDate == yearForPreviousMonth && monthFromUsersDate == previousMonth) {
            expense.setExpenseId(itr -> downloadExpenseId());
            expense.setUserId(itr -> downloadUserId());
            expense.setDate(itr -> downloadDate());
            expense.setItem(itr -> downloadItem());
            expense.setAmount(itr -> downloadAmount());
            expense.setDateAsUnixTime(auxiliaryMethods.changeDateFormatForUnixTime(itr -> downloadDate()));
            expensesOnlyFromPreviousMonth.push_back(expense);
        }
        itr++;
    }
    return expensesOnlyFromPreviousMonth;
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
    cout << "----------INCOMES----------" << endl;
    for(int i = 0; i < incomes.size(); i++) {
        cout<<incomes.at(i).downloadDate()<<" "<<incomes.at(i).downloadItem()<< " " <<incomes.at(i).downloadAmount()<< endl;
    }
}

void FinancialOperationsManager::displayExpensesFromSelectedPeriodOfTime(vector <Expense> expenses)
{
    cout << endl << "---------EXPENSES----------" << endl;
    for(int i = 0; i < expenses.size(); i++) {
        cout<<expenses.at(i).downloadDate()<<" "<<expenses.at(i).downloadItem()<< " " <<expenses.at(i).downloadAmount()<< '\n';
    }
}

double FinancialOperationsManager::sumIncomes (vector <Income> incomes)
{
    double totalIncomes = 0;
    for(int i = 0; i < incomes.size(); i++) {
        totalIncomes += incomes.at(i).downloadAmount();
    }
    return totalIncomes;
}

double FinancialOperationsManager::sumExpenses (vector <Expense> expenses)
{
    double totalExpenses = 0;
    for(int i = 0; i < expenses.size(); i++) {
        totalExpenses += expenses.at(i).downloadAmount();
    }
    return totalExpenses;
}

double FinancialOperationsManager::sumIncomesAndExpenses (double incomes, double expenses)
{
    double balance = incomes - expenses;
    return balance;
}

bool operator<(const Income &i1, const Income &i2) {
    return i1.downloadDateAsUnixTime() < i2.downloadDateAsUnixTime();
}

bool operator<(const Expense &e1, const Expense &e2) {
    return e1.downloadDateAsUnixTime() < e2.downloadDateAsUnixTime();
}









