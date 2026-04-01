#pragma once
#include <string>
using namespace std;
class payment {
public: 
double amount; // stores the payment amount
    string name; // stores the payment name
    bool recurring; // stores whether the payment is recurring or not
    int createdYear; // stores the year the recurring payment was first created
    int createdMonth; // stores the month the recurring payment was first created
payment(); //default constructor
}