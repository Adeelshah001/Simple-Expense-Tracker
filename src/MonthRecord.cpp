#include "../include/MonthRecord.h"

MonthRecord::MonthRecord() {
    month = 1;         // starts the record at January by default
    year = 2026;       // starts the record at a default year
    expenseCount = 0;  // starts with no saved expenses
    incomeCount = 0;   // starts with no saved incomes
}

MonthRecord::MonthRecord(int selectedMonth, int selectedYear) {
    month = selectedMonth; // saves the selected month passed into the constructor
    year = selectedYear;   // saves the selected year passed into the constructor
    expenseCount = 0;      // starts with no saved expenses
    incomeCount = 0;       // starts with no saved incomes
}

void MonthRecord::setMonth(int selectedMonth) {
    month = selectedMonth; // updates the stored month value
}

void MonthRecord::setYear(int selectedYear) {
    year = selectedYear; // updates the stored year value
}

int MonthRecord::getMonth() const {
    return month; // sends back the stored month number
}

int MonthRecord::getYear() const {
    return year; // sends back the stored year number
}

bool MonthRecord::addExpense(Payment expense) {
    if (expenseCount >= MAX_PAYMENTS) {
        return false; // stops the function if the expense array is full
    }

    expenses[expenseCount] = expense; // stores the new expense in the next open position
    expenseCount++;                   // increases the number of saved expenses by 1
    return true;                      // reports that the expense was added successfully
}

bool MonthRecord::addIncome(Payment income) {
    if (incomeCount >= MAX_PAYMENTS) {
        return false; // stops the function if the income array is full
    }

    incomes[incomeCount] = income; // stores the new income in the next open position
    incomeCount++;                 // increases the number of saved incomes by 1
    return true;                   // reports that the income was added successfully
}

double MonthRecord::getTotalExpenses() const {
    double total = 0.0; // stores the running total of all expense amounts

    for (int i = 0; i < expenseCount; i++) {
        total = total + expenses[i].amount; // adds each expense amount to the total
    }

    return total; // sends back the final expense total
}

double MonthRecord::getTotalIncome() const {
    double total = 0.0; // stores the running total of all income amounts

    for (int i = 0; i < incomeCount; i++) {
        total = total + incomes[i].amount; // adds each income amount to the total
    }

    return total; // sends back the final income total
}

double MonthRecord::getBalance() const {
    return getTotalIncome() - getTotalExpenses(); // subtracts expenses from income to get the balance
}

int MonthRecord::getExpenseCount() const {
    return expenseCount; // sends back how many expense entries are stored
}

int MonthRecord::getIncomeCount() const {
    return incomeCount; // sends back how many income entries are stored
}

Payment MonthRecord::getExpenseAt(int index) const {
    return expenses[index]; // sends back the expense at the requested position
}

Payment MonthRecord::getIncomeAt(int index) const {
    return incomes[index]; // sends back the income at the requested position
}
