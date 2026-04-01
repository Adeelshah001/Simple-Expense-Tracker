#include "../include/ExpenseTracker.h"
#include <iostream>
#include <iomanip>
using namespace std;

ExpenseTracker::ExpenseTracker() {
    recordCount = 0;             // starts with no month records saved
    recurringExpenseCount = 0;   // starts with no recurring expenses saved
    recurringIncomeCount = 0;    // starts with no recurring incomes saved
}

int ExpenseTracker::findMonthRecord(int month, int year) const {
    for (int i = 0; i < recordCount; i++) {
        if (records[i].getMonth() == month && records[i].getYear() == year) {
            return i; // returns the matching month record position
        }
    }

    return -1; // returns -1 when the month record is not found
}

int ExpenseTracker::getOrCreateMonthRecord(int month, int year) {
    int index = findMonthRecord(month, year); // stores the position of an existing month record if found

    if (index != -1) {
        return index; // returns the existing month record position
    }

    if (recordCount >= MAX_MONTH_RECORDS) {
        return -1; // stops the function if the records array is already full
    }

    records[recordCount] = MonthRecord(month, year); // creates and stores a new month record

    for (int i = 0; i < recurringExpenseCount; i++) {
        records[recordCount].addExpense(recurringExpenses[i]); // copies each saved recurring expense into the new month
    }

    for (int i = 0; i < recurringIncomeCount; i++) {
        records[recordCount].addIncome(recurringIncomes[i]); // copies each saved recurring income into the new month
    }

    recordCount++;         // increases the total number of month records by 1
    return recordCount - 1; // returns the position of the newly created month record
}

bool ExpenseTracker::addExpenseToMonth(int month, int year, Payment expense) {
    int index = getOrCreateMonthRecord(month, year); // stores the month record position for the selected month

    if (index == -1) {
        return false; // stops the function if the month record could not be created
    }

    return records[index].addExpense(expense); // adds the expense into the selected month record
}

bool ExpenseTracker::addIncomeToMonth(int month, int year, Payment income) {
    int index = getOrCreateMonthRecord(month, year); // stores the month record position for the selected month

    if (index == -1) {
        return false; // stops the function if the month record could not be created
    }

    return records[index].addIncome(income); // adds the income into the selected month record
}

bool ExpenseTracker::saveRecurringExpense(int month, int year, Payment expense) {
    if (recurringExpenseCount >= MAX_RECURRING_PAYMENTS) {
        return false; // stops the function if the recurring expense array is full
    }

    recurringExpenses[recurringExpenseCount] = expense; // stores the recurring expense in the saved list
    recurringExpenseCount++;                            // increases the number of saved recurring expenses by 1

    return addExpenseToMonth(month, year, expense); // also adds the recurring expense into the current month
}

bool ExpenseTracker::saveRecurringIncome(int month, int year, Payment income) {
    if (recurringIncomeCount >= MAX_RECURRING_PAYMENTS) {
        return false; // stops the function if the recurring income array is full
    }

    recurringIncomes[recurringIncomeCount] = income; // stores the recurring income in the saved list
    recurringIncomeCount++;                          // increases the number of saved recurring incomes by 1

    return addIncomeToMonth(month, year, income); // also adds the recurring income into the current month
}

void ExpenseTracker::showMonthlySummary(int month, int year) const {
    int index = findMonthRecord(month, year); // stores the position of the selected month record

    if (index == -1) {
        cout << "\nNo record found for that month.\n"; // tells the user there is no saved record yet
        return;
    }

    cout << "\n--- Summary for " << getMonthName(month) << " " << year << " ---\n";
    cout << fixed << setprecision(2);
    cout << "Total Income : $" << records[index].getTotalIncome() << "\n";
    cout << "Total Expense: $" << records[index].getTotalExpenses() << "\n";
    cout << "Balance      : $" << records[index].getBalance() << "\n";
}

void ExpenseTracker::showRecurringPayments() const {
    int i; // loop counter for printing recurring payments

    cout << "\nSaved Recurring Expenses\n";
    if (recurringExpenseCount == 0) {
        cout << "None\n"; // shows that no recurring expenses are saved
    }
    else {
        for (i = 0; i < recurringExpenseCount; i++) {
            cout << "- " << recurringExpenses[i].name << ": $" << fixed << setprecision(2) << recurringExpenses[i].amount << "\n";
        }
    }

    cout << "\nSaved Recurring Income\n";
    if (recurringIncomeCount == 0) {
        cout << "None\n"; // shows that no recurring incomes are saved
    }
    else {
        for (i = 0; i < recurringIncomeCount; i++) {
            cout << "- " << recurringIncomes[i].name << ": $" << fixed << setprecision(2) << recurringIncomes[i].amount << "\n";
        }
    }
}

string ExpenseTracker::getMonthName(int month) const {
    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Invalid"; // returns Invalid when the month number is outside 1 to 12
    }
}
