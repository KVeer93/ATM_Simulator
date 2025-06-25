#pragma once
#include <string>
#include <vector>
using namespace std;

extern vector<string> transactionHistory;

class Account
{
private:
    string accountNumber;
    string holderName;
    double balance;
    string pin;

public:
    Account(string accNum, string name, double bal, string pinCode);
    bool verifyPin() const;
    void withdraw();
    void deposit();
    void checkBalance() const;
    void showTransactionHistory() const;
    void saveToFile() const;
    void showMenu();
};