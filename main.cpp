#include "Account.hpp"
#include "utils.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

extern vector<string> transactionHistory;

int main()
{
    cout << "Do you already have an account? (y/n): ";
    string choice = getString();

    Account acc1 = (choice == "y") ? [&]() -> Account {
        cout << "Enter your 10-digit account number: ";
        string acc = getString();
        assert(acc.length() == 4 && all_of(acc.begin(), acc.end(), ::isdigit) && "Account Number must be 10 numeric digits");

        Account loaded = loadFromFile(acc);
        
        if (!loaded.verifyPin())
        {
            cerr << "Wrong PIN. Access denied.\n";
            exit(1);
        }

        return loaded;
    }() : [&]() -> Account {
        cout << "=== Creating a new account ===\n";

        cout << "Enter your name: ";
        string name = getString();

        cout << "Enter a 4-digit PIN: ";
        string pin = getString();
        assert(pin.length() == 4 && all_of(pin.begin(), pin.end(), ::isdigit) && "PIN must be 4 numeric digits");

        cout << "Enter initial balance: ";
        double balance = getDouble();

        cout << "Enter 10-digit account number: ";
        string acc = getString();
        assert(acc.length() == 10 && all_of(acc.begin(), acc.end(), ::isdigit) && "Account number must be 10 digits");

        return Account(acc, name, balance, pin);
    }();

    acc1.showMenu();
    acc1.saveToFile();
    return 0;
}


// 1. File Handling (Save & Load Accounts)
// 🧍 2. Multiple Users Support
// 🔐 3. Limit Login Attempts
// 📊 4. Account Summary & Statements
// 🪙 5. Interest Feature
// 🌐 6. Internationalization (Currency + Language)
// ⚖️ 7. Transfer Between Accounts
// 📅 8. Timestamps for Transactions
// 🧪 9. Unit Testing
// 🧬 10. Inheritance – Different Account Types
// 📱 11. Build GUI or Mobile Version
// ☠️ 12. Admin Mode
// 🧾 13. Receipt Generation
// ⚔️ 14. Error Handling Overhaul
// 🎮 15. Gamify Banking (because why not?)
// 🧠 Stretch Goal: AI Chat Assistant for Banking