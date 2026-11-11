#include <iostream>
using namespace std;

constexpr long long BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

enum class Zone { Inner, Middle, Outer };

int main() {
    Zone zone = Zone::Outer;
    int zoneIndex = static_cast<int>(zone);

    cout << "Inner fare: " << BASE_PAISE[0] << " paise\n";
    cout << "Middle fare: " << BASE_PAISE[1] << " paise\n";
    cout << "Outer fare: " << BASE_PAISE[2] << " paise\n";
    cout << "Peak surcharge: " << PEAK_SURCHARGE_PERCENT << "%\n";
    cout << "Minimum balance: " << MIN_BALANCE_PAISE << " paise\n";
    cout << "Selected zone index: " << zoneIndex << '\n';
}
