#include <iostream>
using namespace std;

class SmartCard {
private:
    long long balance;
    static constexpr long long MIN_BALANCE = 5000;

public:
    explicit SmartCard(long long initialBalance) : balance(initialBalance) {}

    bool canTravel(long long fare) const {
        return fare >= 0 && balance - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balance -= fare;
        return true;
    }

    long long getBalance() const { return balance; }
};

int main() {
    SmartCard card(10000);
    if (card.deduct(2000))
        cout << "Journey Allowed\n";
    else
        cout << "Journey Denied\n";
    cout << "Balance: " << card.getBalance() << " paise\n";
}
