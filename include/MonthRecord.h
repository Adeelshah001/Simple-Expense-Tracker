#ifndef MONTHRECORD_H
#define MONTHRECORD_H

#include "Payment.h"

const int MAX_PAYMENTS = 100; // maximum number of expense or income entries per month

class MonthRecord {
private:
    int month;                          // stores the selected month number
    int year;                           // stores the selected year
    Payment expenses[MAX_PAYMENTS];     // stores all expense payments for the month
    Payment incomes[MAX_PAYMENTS];      // stores all income payments for the month
    int expenseCount;                   // stores how many expense entries are currently used
    int incomeCount;                    // stores how many income entries are currently used

public:
    MonthRecord();                         // default constructor for an empty month record
    MonthRecord(int selectedMonth, int selectedYear); // constructor that sets month and year

    void setMonth(int selectedMonth);      // sets the month value
    void setYear(int selectedYear);        // sets the year value
    int getMonth() const;                  // returns the stored month value
    int getYear() const;                   // returns the stored year value

    bool addExpense(Payment expense);      // adds one expense payment if there is space
    bool addIncome(Payment income);        // adds one income payment if there is space

    double getTotalExpenses() const;       // returns the total expense amount for the month
    double getTotalIncome() const;         // returns the total income amount for the month
    double getBalance() const;             // returns income minus expenses

    int getExpenseCount() const;           // returns the number of saved expenses
    int getIncomeCount() const;            // returns the number of saved incomes
    Payment getExpenseAt(int index) const; // returns one expense at a specific position
    Payment getIncomeAt(int index) const;  // returns one income at a specific position
};

#endif