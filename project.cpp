#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(const string& number, const string& name, double initialBalance)
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    const string& getAccountNumber() {
        return accountNumber;
    }

    const string& getAccountHolderName() {
        return accountHolderName;
    }

    void displayAccount() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    // Member functions
    void createAccount(const string& number, const string& name, double initialBalance) {
        Account newAccount(number, name, initialBalance);
        accounts.push_back(newAccount);
        cout << "Account created successfully." << endl;
    }

    Account* findAccount(const string& accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }
};

void displayMenu() {
    cout << "===== Bank Management System =====" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Balance Enquiry" << endl;
    cout << "5. Display Account" << endl;
    cout << "6. Exit" << endl;
    cout << "===================================" << endl;
}

int main() {
    Bank bank;

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string number, name;
                double initialBalance;
                cout << "Enter account number: ";
                cin >> number;
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter initial balance: ";
                cin >> initialBalance;

                bank.createAccount(number, name, initialBalance);
                break;
            }
            case 2: {
                string accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                Account* account = bank.findAccount(accountNumber);
                if (account) {
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 3: {
                string accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                Account* account = bank.findAccount(accountNumber);
                if (account) {
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 4: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                Account* account = bank.findAccount(accountNumber);
                if (account) {
                    cout << "Balance: " << account->getBalance() << endl;
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 5: {
                string accountNumber;
                cout << "Enter account number to display: ";
                cin >> accountNumber;
                Account* account = bank.findAccount(accountNumber);
                if (account) {
                    account->displayAccount();
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 6);

    return 0;
}
