#include "FileWithExpenses.h"

vector <Expense> FileWithExpenses::loadExpensesOfLoggedInUserFromFile(int loggedInUserId) {
    CMarkup expensesFile;
    expensesFile.Load( nameOfTheFileWithExpenses );
    expensesFile.ResetPos();
    expensesFile.FindElem();
    expensesFile.IntoElem();
    while (true) {
        bool ifNextPositionExists = expensesFile.FindElem();
        if (ifNextPositionExists == false) {
            break;
        }
        string expenseIdAsAString = expensesFile.GetElemContent();
        int expenseId = atoi(expenseIdAsAString.c_str());
        expense.setExpenseId(expenseId);
        expensesFile.FindElem();
        string userIdAsAString = expensesFile.GetElemContent();
        int userId = atoi(userIdAsAString.c_str());
        expense.setUserId(userId);
        expensesFile.FindElem();
        string date = expensesFile.GetElemContent();
        expense.setDate(date);
        expensesFile.FindElem();
        string item = expensesFile.GetElemContent();
        expense.setItem(item);
        expensesFile.FindElem();
        string amountAsAString = expensesFile.GetElemContent();
        stringstream ss;
        double amountAsADouble;
        ss << amountAsAString;
        ss >> amountAsADouble;
        expense.setAmount(amountAsADouble);
        idOfLastExpense++;
        if (loggedInUserId == expense.downloadUserId()) {
            expenses.push_back(expense);
        }
    }
    return expenses;
}

int FileWithExpenses::getTheIdOfLastExpense() {
    return idOfLastExpense;
}

void FileWithExpenses::addExpenseToFile(Expense expense) {
    CMarkup expensesFile;
    bool ifFileWithexpensesExists = expensesFile.Load( nameOfTheFileWithExpenses );
    if (ifFileWithexpensesExists == false) {
        expensesFile.AddElem( "ExpensesList" );
        expensesFile.IntoElem();
    }
    expensesFile.FindElem();
    expensesFile.IntoElem();
    expensesFile.AddElem( "expenseId", expense.downloadExpenseId() );
    expensesFile.AddElem( "userId", expense.downloadUserId() );
    expensesFile.AddElem( "date", expense.downloadDate() );
    expensesFile.AddElem( "item", expense.downloadItem() );
    ostringstream strs;
    strs << expense.downloadAmount();
    string amountAsString = strs.str();
    expensesFile.AddElem( "amount", amountAsString );
    expensesFile.Save( nameOfTheFileWithExpenses );
}
