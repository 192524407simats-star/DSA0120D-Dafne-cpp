#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const long long farePaise = 3000;
    const long long journeyCounts[] = {20000, 500000, 3000000};

    cout << fixed << setprecision(2);
    for (long long n : journeyCounts) {
        long long totalPaise = n * farePaise;
        double totalRupees = static_cast<double>(n) * 30.0;

        cout << "Journeys: " << n << '\n';
        cout << "Integer-paise total: " << totalPaise << " paise\n";
        cout << "Integer-paise total: Rs " << totalPaise / 100.0 << '\n';
        cout << "Double total: Rs " << totalRupees << "\n\n";
    }
}
