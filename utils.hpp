#pragma once
#include <string>
#include "Account.hpp"
using namespace std;

extern vector<string> transactionHistory;

Account loadFromFile(const string &accountNumber);
void ignoreLine();
bool clearFailedExtraction();
double getDouble();
string getString();
