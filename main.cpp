#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Payment {
public:
    string name;
    double amount{};

    Payment() = default;
    Payment(const string& n, double a) : name(n), amount(a) {}
};

class MonthRecord {
public:
    int month{};
    int year{};
    vector<Payment> expenses;
    vector<Payment> incomes;

    MonthRecord() = default;
    MonthRecord(int m, int y) : month(m), year(y) {}

    double totalExpenses() const {
        double total = 0.0;
        for (const auto& item : expenses) total += item.amount;
        return total;
    }

    double totalIncome() const {
        double total = 0.0;
        for (const auto& item : incomes) total += item.amount;
        return total;
    }

    double balance() const {
        return totalIncome() - totalExpenses();
    }
};

string monthName(int month) {
    const string months[] = {
        "Invalid", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    if (month < 1 || month > 12) return "Invalid";
    return months[month];
}

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout << "Invalid input. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double readDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout << "Invalid input. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string readLine(const string& prompt) {
    cout << prompt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string text;
    getline(cin, text);
    return text;
}

MonthRecord* findMonthRecord(vector<MonthRecord>& records, int month, int year) {
    for (auto& record : records) {
        if (record.month == month && record.year == year) return &record;
    }
    return nullptr;
}

MonthRecord& getOrCreateMonthRecord(vector<MonthRecord>& records, int month, int year,
                                    const vector<Payment>& savedRecurringExpenses,
                                    const vector<Payment>& savedRecurringIncome) {
    MonthRecord* existing = findMonthRecord(records, month, year);
    if (existing != nullptr) return *existing;

    MonthRecord record(month, year);
    record.expenses = savedRecurringExpenses;
    record.incomes = savedRecurringIncome;
    records.push_back(record);
    return records.back();
}

void showMonthlySummary(const MonthRecord& record) {
    cout << "\n--- Summary for " << monthName(record.month) << ' ' << record.year << " ---\n";
    cout << fixed << setprecision(2);
    cout << "Total Income : $" << record.totalIncome() << "\n";
    cout << "Total Expense: $" << record.totalExpenses() << "\n";
    cout << "Balance      : $" << record.balance() << "\n";
}

int main() {
    vector<MonthRecord> records;
    vector<Payment> savedRecurringExpenses;
    vector<Payment> savedRecurringIncome;

    cout << "Simple Monthly Expense Tracker\n";

    while (true) {
        cout << "\nMenu\n";
        cout << "1. Enter expense\n";
        cout << "2. Enter income\n";
        cout << "3. Save recurring expense\n";
        cout << "4. Save recurring income\n";
        cout << "5. View monthly summary\n";
        cout << "6. View saved recurring payments\n";
        cout << "0. Exit\n";

        int choice = readInt("Choose an option: ");

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice < 0 || choice > 6) {
            cout << "Invalid menu choice.\n";
            continue;
        }

        int month = readInt("Enter month (1-12): ");
        int year = readInt("Enter year: ");

        if (month < 1 || month > 12) {
            cout << "Invalid month.\n";
            continue;
        }

        MonthRecord& record = getOrCreateMonthRecord(records, month, year, savedRecurringExpenses, savedRecurringIncome);

        if (choice == 1) {
            string name = readLine("Enter expense name: ");
            double amount = readDouble("Enter expense amount: $");
            record.expenses.emplace_back(name, amount);
            cout << "Expense added to " << monthName(month) << ' ' << year << ".\n";
        }
        else if (choice == 2) {
            string name = readLine("Enter income name: ");
            double amount = readDouble("Enter income amount: $");
            record.incomes.emplace_back(name, amount);
            cout << "Income added to " << monthName(month) << ' ' << year << ".\n";
        }
        else if (choice == 3) {
            string name = readLine("Enter recurring expense name: ");
            double amount = readDouble("Enter recurring expense amount: $");
            Payment payment(name, amount);
            savedRecurringExpenses.push_back(payment);
            record.expenses.push_back(payment);
            cout << "Recurring expense saved and added to this month.\n";
        }
        else if (choice == 4) {
            string name = readLine("Enter recurring income name: ");
            double amount = readDouble("Enter recurring income amount: $");
            Payment payment(name, amount);
            savedRecurringIncome.push_back(payment);
            record.incomes.push_back(payment);
            cout << "Recurring income saved and added to this month.\n";
        }
        else if (choice == 5) {
            showMonthlySummary(record);
        }
        else if (choice == 6) {
            cout << "\nSaved Recurring Expenses\n";
            if (savedRecurringExpenses.empty()) {
                cout << "None\n";
            } else {
                for (const auto& payment : savedRecurringExpenses) {
                    cout << "- " << payment.name << ": $" << fixed << setprecision(2) << payment.amount << "\n";
                }
            }

            cout << "\nSaved Recurring Income\n";
            if (savedRecurringIncome.empty()) {
                cout << "None\n";
            } else {
                for (const auto& payment : savedRecurringIncome) {
                    cout << "- " << payment.name << ": $" << fixed << setprecision(2) << payment.amount << "\n";
                }
            }
        }
    }

    return 0;
}
