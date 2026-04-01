#include <iostream>
#include <string>
#include "../include/ExpenseTracker.h"
using namespace std;

int readInt(string prompt) {
    int value; // stores the whole number entered by the user

    cout << prompt;
    cin >> value;
    return value; // sends back the whole number that the user entered
}

double readDouble(string prompt) {
    double value; // stores the decimal number entered by the user

    cout << prompt;
    cin >> value;
    return value; // sends back the decimal number that the user entered
}

string readText(string prompt) {
    string text; // stores the text entered by the user

    cout << prompt;
    cin.ignore();
    getline(cin, text);
    return text; // sends back the full line of text that the user entered
}

int main() {
    ExpenseTracker tracker; // creates the main expense tracker object used by the program
    int choice;             // stores the menu option chosen by the user
    int month;              // stores the selected month entered by the user
    int year;               // stores the selected year entered by the user
    string name;            // stores the name of an income or expense payment
    double amount;          // stores the amount of an income or expense payment
    bool success;           // stores whether an add or save action worked

    cout << "Simple Monthly Expense Tracker\n";

    do {
        cout << "\nMenu\n";
        cout << "1. Enter expense\n";
        cout << "2. Enter income\n";
        cout << "3. Save recurring expense\n";
        cout << "4. Save recurring income\n";
        cout << "5. View monthly summary\n";
        cout << "6. View saved recurring payments\n";
        cout << "0. Exit\n";

        choice = readInt("Choose an option: ");

        if (choice == 0) {
            cout << "Goodbye!\n";
        }
        else if (choice >= 1 && choice <= 6) {
            month = readInt("Enter month (1-12): ");
            year = readInt("Enter year: ");

            if (month < 1 || month > 12) {
                cout << "Invalid month.\n";
            }
            else if (choice == 1) {
                name = readText("Enter expense name: ");
                amount = readDouble("Enter expense amount: $");
                success = tracker.addExpenseToMonth(month, year, Payment(name, amount));

                if (success) {
                    cout << "Expense added.\n";
                }
                else {
                    cout << "Expense could not be added.\n";
                }
            }
            else if (choice == 2) {
                name = readText("Enter income name: ");
                amount = readDouble("Enter income amount: $");
                success = tracker.addIncomeToMonth(month, year, Payment(name, amount));

                if (success) {
                    cout << "Income added.\n";
                }
                else {
                    cout << "Income could not be added.\n";
                }
            }
            else if (choice == 3) {
                name = readText("Enter recurring expense name: ");
                amount = readDouble("Enter recurring expense amount: $");
                success = tracker.saveRecurringExpense(month, year, Payment(name, amount));

                if (success) {
                    cout << "Recurring expense saved.\n";
                }
                else {
                    cout << "Recurring expense could not be saved.\n";
                }
            }
            else if (choice == 4) {
                name = readText("Enter recurring income name: ");
                amount = readDouble("Enter recurring income amount: $");
                success = tracker.saveRecurringIncome(month, year, Payment(name, amount));

                if (success) {
                    cout << "Recurring income saved.\n";
                }
                else {
                    cout << "Recurring income could not be saved.\n";
                }
            }
            else if (choice == 5) {
                tracker.showMonthlySummary(month, year);
            }
            else if (choice == 6) {
                tracker.showRecurringPayments();
            }
        }
        else {
            cout << "Invalid menu choice.\n";
        }

    } while (choice != 0);

    return 0; // ends the program successfully
}
