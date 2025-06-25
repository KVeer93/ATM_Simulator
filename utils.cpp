#include "utils.hpp"
#include "Account.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

vector<string> transactionHistory;
const string ACCOUNT_FOLDER = "AccountHistory/";

void ignoreLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
    if (!cin)
    {
        if (cin.eof())
            exit(0);
        cin.clear();
        ignoreLine();
        return true;
    }
    return false;
}

double getDouble()
{
    while (true)
    {
        double x;
        cin >> x;
        if (clearFailedExtraction())
        {
            cout << "Invalid number. Please try again.\n";
            continue;
        }
        ignoreLine();
        return x;
    }
}

string getString()
{
    while (true)
    {
        string s;
        cin >> s;
        if (clearFailedExtraction())
        {
            cout << "Invalid input. Please try again.\n";
            continue;
        }
        ignoreLine();
        return s;
    }
}

Account loadFromFile(const string &accountNumber)
{
    ifstream inFile(ACCOUNT_FOLDER + accountNumber + ".txt");
    if (!inFile)
    {
        cerr << "Failed to open account file for reading.\n";
        exit(1);
    }

    string accNum, name, pin;
    double bal;
    size_t historyCount;

    getline(inFile, accNum);
    getline(inFile, name);
    inFile >> bal;
    inFile.ignore();
    getline(inFile, pin);
    inFile >> historyCount;
    inFile.ignore();

    transactionHistory.clear();
    for (size_t i = 0; i < historyCount; ++i)
    {
        string entry;
        getline(inFile, entry);
        transactionHistory.push_back(entry);
    }

    cout << "Account loaded successfully.\n";
    return Account(accNum, name, bal, pin);
}
