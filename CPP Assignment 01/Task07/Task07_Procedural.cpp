#include <iostream>
using namespace std;

long long balance = 10000;
constexpr long long MIN_BALANCE = 5000;

bool canTravel(long long fare) {
    return fare >= 0 && balance - fare >= MIN_BALANCE;
}

bool deduct(long long fare) {
    if (!canTravel(fare)) return false;
    balance -= fare;
    return true;
}

int main() {
    long long fare = 2000;
    if (deduct(fare))
        cout << "Journey Allowed\n";
    else
        cout << "Journey Denied\n";
    cout << "Balance: " << balance << " paise\n";
}
