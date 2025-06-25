# 🏦 ATM Simulator (CLI-Based)

Welcome to the **ATM Simulator**, a command-line banking system crafted with elegant C++.
Because real kings don't just withdraw money—they write the code that runs the ATM. 💻👑

---

## ✨ Features

* 💳 Secure PIN-based login
* 💰 Withdraw and Deposit funds
* 📈 Real-time Balance Checking
* 🧾 Transaction History Tracker
* 📁 File-based Data Persistence
* 📓 Account data stored in a separate `AccountHistory/` folder

---

## 🧰 Tech Stack

| Category       | Tech Used                 |
| -------------- | ------------------------- |
| Language       | C++                       |
| Input Handling | `iostream`                |
| File I/O       | `fstream`                 |
| Build System   | CMake / g++               |
| Structure      | Modular (Classes + Utils) |

---

## 🏗️ Build & Run Instructions

### 🚀 Option 1: Using CMake (Recommended)

```bash
mkdir build && cd build
cmake ..
make
./atm_sim
```

### 🧪 Option 2: Using g++ Directly

```bash
g++ main.cpp Account.cpp utils.cpp -o atm_sim
./atm_sim
```

---

## 📂 Project Structure

```
ATM-Simulator/
├── main.cpp                 # Entry point
├── Account.hpp / Account.cpp  # Account class (withdraw, deposit, verify, etc.)
├── utils.hpp / utils.cpp    # Utility functions (I/O, validation, etc.)
├── AccountHistory/          # 📂 Account data stored here
├── CMakeLists.txt           # For building via CMake
├── .gitignore
└── README.md
```

---

## 📈 Planned Upgrades (Future Goals)

* 🢍 Multi-user support
* 🔐 Limited login attempts
* �� Interest calculation
* ⚖️ Inter-account transfers
* 📊 Account summary generation
* 🧾 Receipt generation (TXT-based)
* ☠️ Admin mode
* 📅 Timestamped transactions
* 🌐 Multi-language & currency support
* 🧪 Unit testing
* 🦮 Account inheritance (e.g. Savings, Checking)
* 📱 GUI/Mobile version
* 🎮 Gamification features (achievement system)

---

## 🤘 Contributing

Want to help make the ultimate terminal banking simulator?
Fork it, clone it, break it, fix it, commit it, push it.

---

## 📜 License

MIT License. Steal it, tweak it, just don’t forget to star it ⭐

---

> “Bank like a boss. Code like a king.” 👑
