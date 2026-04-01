#ifndef EXPENSETRACKER_H
#define EXPENSETRACKER_H

#include "MonthRecord.h"
#include <string>
using namespace std;

const int MAX_MONTH_RECORDS = 24;        // maximum number of month records saved in the program
const int MAX_RECURRING_PAYMENTS = 50;   // maximum number of recurring expenses or incomes saved

class ExpenseTracker {
private:
    MonthRecord records[MAX_MONTH_RECORDS];           // stores all month records created in the program
    int recordCount;                                  // stores how many month records are currently used

    Payment recurringExpenses[MAX_RECURRING_PAYMENTS]; // stores saved recurring expenses
    Payment recurringIncomes[MAX_RECURRING_PAYMENTS];  // stores saved recurring incomes
    int recurringExpenseCount;                         // stores how many recurring expenses are saved
    int recurringIncomeCount;                          // stores how many recurring incomes are saved

public:
    ExpenseTracker(); // constructor that starts the tracker with empty records

    int findMonthRecord(int month, int year) const;              // finds the position of a month record if it exists
    int getOrCreateMonthRecord(int month, int year);             // returns a month record position or creates one if missing

    bool addExpenseToMonth(int month, int year, Payment expense); // adds one expense to a selected month
    bool addIncomeToMonth(int month, int year, Payment income);   // adds one income to a selected month

    bool saveRecurringExpense(int month, int year, Payment expense); // saves a recurring expense and adds it to the current month
    bool saveRecurringIncome(int month, int year, Payment income);   // saves a recurring income and adds it to the current month

    void showMonthlySummary(int month, int year) const;          // displays the summary for one selected month
    void showRecurringPayments() const;                          // displays all saved recurring expenses and incomes

    string getMonthName(int month) const;                        // returns the text name of the month number
};

#endif