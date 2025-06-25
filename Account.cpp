#include "Account.hpp"
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cstdlib>  // For system()
using namespace std;

const string ACCOUNT_FOLDER = "AccountHistory/";

// External transaction history
extern vector<string> transactionHistory;

Account::Account(string accNum, string name, double bal, string pinCode)
    : accountNumber{accNum}, holderName{name}, balance{bal}, pin{pinCode}
{
    assert(accNum.length() == 10 && "Account number must be 10 digits");
    assert(balance >= 0.0 && "Balance cannot be negative");
}

bool Account::verifyPin() const
{
    cout << "Enter PIN: ";
    string enteredPin = getString();
    return enteredPin == pin;
}

void Account::withdraw()
{
    cout << "Enter amount to withdraw: ";
    double amount = getDouble();
    assert(amount > 0 && "Withdraw amount must be positive");

    if (amount > balance)
    {
        cerr << "Insufficient balance\n";
        transactionHistory.push_back("Failed withdrawal of ₹" + to_string(amount));
        return;
    }

    balance -= amount;
    transactionHistory.push_back("Withdrew ₹" + to_string(amount));
    cout << "₹" << amount << " withdrawn successfully.\n";
}

void Account::deposit()
{
    cout << "Enter amount to deposit: ";
    double amount = getDouble();
    assert(amount > 0 && "Deposit amount must be positive");

    balance += amount;
    transactionHistory.push_back("Deposited ₹" + to_string(amount));
    cout << "₹" << amount << " deposited successfully.\n";
}

void Account::checkBalance() const
{
    cout << "Current balance: ₹" << balance << "\n";
}

void Account::showTransactionHistory() const
{
    cout << "\n--- Transaction History ---\n";
    if (transactionHistory.empty())
    {
        cout << "No transactions yet.\n";
    }
    else
    {
        for (const string &record : transactionHistory)
            cout << "- " << record << "\n";
    }
}

void Account::saveToFile() const
{
    system(("mkdir -p " + ACCOUNT_FOLDER).c_str()); // Linux/macOS only

    ofstream outFile(ACCOUNT_FOLDER + accountNumber + ".txt");
    if (!outFile)
    {
        cerr << "Failed to open file for writing.\n";
        return;
    }

    outFile << accountNumber << '\n';
    outFile << holderName << '\n';
    outFile << balance << '\n';
    outFile << pin << '\n';

    outFile << transactionHistory.size() << '\n';
    for (const string &entry : transactionHistory)
        outFile << entry << '\n';

    outFile.close();
    cout << "Account saved to file successfully.\n";
}

void Account::showMenu()
{
    if (!verifyPin())
    {
        cerr << "Access Denied. Wrong PIN.\n";
        return;
    }

    while (true)
    {
        cout << "\n--- ATM Menu ---\n";
        cout << "1. Withdraw\n";
        cout << "2. Deposit\n";
        cout << "3. Check Balance\n";
        cout << "4. Show Transaction History\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";

        int choice = static_cast<int>(getDouble());

        switch (choice)
        {
        case 1:
            withdraw();
            break;
        case 2:
            deposit();
            break;
        case 3:
            checkBalance();
            transactionHistory.push_back("Checked balance");
            break;
        case 4:
            showTransactionHistory();
            break;
        case 0:
            cout << "Thanks for banking with us, " << holderName << ". Goodbye!\n";
            return;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    }
}
