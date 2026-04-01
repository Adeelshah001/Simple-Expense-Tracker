#pragma once
#include <string>
using namespace std;
class Payment {
public:
    double amount;
    string name;
    bool recurring;
    int createdYear;
    int createdMonth;
    Payment();
    Payment(double paymentAmount, string paymentName, bool isRecurring, int year, int month);
};