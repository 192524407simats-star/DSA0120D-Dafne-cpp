#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;
    double transactions[10];
    int count;

    void addTransaction(double amount) {
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 1; i < 10; ++i)
                transactions[i - 1] = transactions[i];
            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(const string& number, double opening)
        : accountNumber(number), balance(opening), count(0) {}

    void deposit(double amount);
    bool withdraw(double amount);
    void miniStatement() const;
};

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) return;
    balance += amount;
    addTransaction(amount);
}
bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    addTransaction(-amount);
    return true;
}
void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber
         << "\nBalance: " << balance
         << "\nRecent transactions:\n";
    for (int i = 0; i < count; ++i)
        cout << transactions[i] << '\n';
}
int main() {
    SavingsAccount account("SB1001", 1000);
    account.deposit(500);
    account.withdraw(200);
    account.deposit(100);
    account.miniStatement();
}