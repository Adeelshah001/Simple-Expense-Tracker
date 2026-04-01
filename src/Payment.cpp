#include "../include/Payment.h"

Payment::Payment() {
    name = "";      // starts with an empty payment name
    amount = 0.0;   // starts with a zero dollar amount
}

Payment::Payment(string paymentName, double value) {
    name = paymentName; // saves the payment name passed into the constructor
    amount = value;     // saves the payment amount passed into the constructor
}
