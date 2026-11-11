#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

constexpr long long MIN_BALANCE = 5000;

long long calculateFare(int zone, int hour) {
    long long fare;
    switch (zone) {
        case 1: fare = 1000; break;
        case 2: fare = 2000; break;
        case 3: fare = 3000; break;
        default: return -1;
    }

    if (hour < 0 || hour > 23) return -1;
    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    if (peak) fare += fare * 20 / 100;
    return fare;
}

int main() {
    long long balance = 20000; // Rs 200.00
    int zone, hour;

    for (int i = 1; i <= 5; ++i) {
        cout << "Journey " << i << " - enter zone and hour: ";
        if (!(cin >> zone >> hour)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; journey skipped\n";
            continue;
        }

        long long fare = calculateFare(zone, hour);
        if (fare < 0) {
            cout << "Invalid zone or hour; journey skipped\n";
            continue;
        }

        if (balance - fare >= MIN_BALANCE) {
            balance -= fare;
            cout << "Fare Rs " << fare / 100 << '.'
                 << setw(2) << setfill('0') << fare % 100
                 << setfill(' ') << " | Balance Rs "
                 << balance / 100 << '.'
                 << setw(2) << setfill('0') << balance % 100
                 << setfill(' ') << '\n';
        } else {
            cout << "Journey denied: minimum Rs 50 must remain\n";
        }
    }
    return 0;
}
