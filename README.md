# 🏦 ATM Simulator (CLI-based)

Welcome to the **ATM Simulator**, a command-line based banking system written in glorious C++.  
Because real kings write their own ATMs 💻👑

## 🚀 Features

- 💰 Withdraw and deposit cash
- 👀 Check account balance
- 🧾 View transaction history
- 📁 Save & load user account data from files
- 🔐 PIN verification
- 🗃️ Transaction storage in separate `AccountHistory/` folder

## 🔧 Technologies

- Language: C++
- File Handling: `<fstream>`
- CLI Input Handling
- Organized using classes, headers, and utility files

## 🛠️ Build Instructions

```bash
# If you have CMake
mkdir build && cd build
cmake ..
make
./atm_sim

# OR plain g++
g++ main.cpp Account.cpp utils.cpp -o atm_sim
./atm_sim

```

## 🛠️ Build Instructions
ATM-Simulator/
├── main.cpp
├── Account.hpp / Account.cpp
├── utils.hpp / utils.cpp
├── AccountHistory/   # <- Your royal account data
├── .gitignore
└── README.md


## Future Plans
  File Handling (Save & Load Accounts)
 🧍 Multiple Users Support
 🔐 Limit Login Attempts
 📊 Account Summary & Statements
 🪙 Interest Feature
 🌐 Internationalization (Currency + Language)
 ⚖️ Transfer Between Accounts
 📅 Timestamps for Transactions
 🧪 Unit Testing
 🧬 Inheritance – Different Account Types
 📱 Build GUI or Mobile Version
 ☠️ Admin Mode
 🧾 Receipt Generation
 ⚔️ Error Handling Overhaul
 🎮 Gamify Banking (because why not?)