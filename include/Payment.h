#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
using namespace std;

class Payment {
public:
    string name;      // stores the name of the payment
    double amount;    // stores the dollar amount of the payment

    Payment();                                // default constructor for an empty payment
    Payment(string paymentName, double value); // constructor that sets the payment name and amount
};

#endif