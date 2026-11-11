#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int zone, hour;
    cout << "Enter zone (1-3): ";
    if (!(cin >> zone)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid zone input\n";
        return 1;
    }

    cout << "Enter hour (0-23): ";
    if (!(cin >> hour)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid hour input\n";
        return 1;
    }

    if (zone < 1 || zone > 3 || hour < 0 || hour > 23) {
        cout << "Input out of range\n";
        return 1;
    }

    long long fare = (zone == 1 ? 1000 : zone == 2 ? 2000 : 3000);
    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    if (peak) fare += fare * 20 / 100;

    cout << fixed << setprecision(2);
    cout << "Fare: Rs " << fare / 100.0 << '\n';
}
