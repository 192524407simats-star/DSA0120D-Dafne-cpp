#include <iostream>
using namespace std;

enum class Zone { Inner = 0, Middle = 1, Outer = 2 };

class FareTable {
private:
    static constexpr long long fares[3] = {1000, 2000, 3000};
public:
    static long long getFare(Zone zone) {
        int index = static_cast<int>(zone);
        if (index < 0 || index >= 3) return -1;
        return fares[index];
    }
};

class SmartCard {
private:
    long long balance;
    static constexpr long long MIN_BALANCE = 5000;
public:
    explicit SmartCard(long long amount) : balance(amount) {}

    bool deduct(long long fare) {
        if (fare < 0 || balance - fare < MIN_BALANCE) return false;
        balance -= fare;
        return true;
    }

    long long getBalance() const { return balance; }
};

int main() {
    SmartCard card(10000);
    Zone selectedZone = Zone::Outer;
    bool peak = true;

    long long fare = FareTable::getFare(selectedZone);
    if (fare < 0) {
        cout << "Invalid zone\n";
        return 1;
    }
    if (peak) fare += fare * 20 / 100;

    cout << "Calculated fare: " << fare << " paise\n";
    if (card.deduct(fare))
        cout << "Journey allowed\n";
    else
        cout << "Journey denied\n";
    cout << "Remaining balance: " << card.getBalance() << " paise\n";
}
