#include <iostream>
#include <array>
#include <string>
using namespace std;

enum class Zone { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };
enum class DayType { Weekday, Weekend };

class FareTable {
private:
    static constexpr array<long long, 4> fares = {1000, 2000, 3000, 6000};
public:
    static long long getFare(Zone zone) {
        size_t index = static_cast<size_t>(zone);
        if (index >= fares.size()) return -1;
        return fares[index];
    }
};

class MonthlyPass {
private:
    bool active;
    bool coversInner;
    bool coversMiddle;
    bool coversOuter;
    bool coversAirport;

public:
    MonthlyPass(bool inner, bool middle, bool outer, bool airport)
        : active(true), coversInner(inner), coversMiddle(middle),
          coversOuter(outer), coversAirport(airport) {}

    bool covers(Zone zone) const {
        if (!active) return false;
        switch (zone) {
            case Zone::Inner: return coversInner;
            case Zone::Middle: return coversMiddle;
            case Zone::Outer: return coversOuter;
            case Zone::Airport: return coversAirport;
        }
        return false;
    }
};

class SmartCard {
private:
    long long balance;
    static constexpr long long MIN_BALANCE = 5000;
public:
    explicit SmartCard(long long amount) : balance(amount) {}

    bool pay(long long fare) {
        if (fare < 0 || balance - fare < MIN_BALANCE) return false;
        balance -= fare;
        return true;
    }

    long long getBalance() const { return balance; }
};

long long calculateFare(Zone zone, int hour, DayType day,
                        const MonthlyPass& pass) {
    if (pass.covers(zone)) return 0;

    long long fare = FareTable::getFare(zone);
    if (fare < 0 || hour < 0 || hour > 23) return -1;

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    // Weekend discount does not combine with peak surcharge.
    if (day == DayType::Weekend) {
        fare -= fare * 10 / 100;
    } else if (peak) {
        fare += fare * 20 / 100;
    }

    return fare;
}

int main() {
    // Pass covers Inner and Middle: exactly two selected zones.
    MonthlyPass pass(true, true, false, false);
    SmartCard card(20000); // Rs 200.00

    struct Trip {
        Zone zone;
        int hour;
        DayType day;
    };

    Trip trips[] = {
        {Zone::Inner, 9, DayType::Weekday},
        {Zone::Outer, 9, DayType::Weekday},
        {Zone::Airport, 12, DayType::Weekend},
        {Zone::Middle, 18, DayType::Weekend}
    };

    for (const Trip& trip : trips) {
        long long fare = calculateFare(trip.zone, trip.hour, trip.day, pass);

        if (fare < 0) {
            cout << "Invalid journey\n";
        } else if (fare == 0) {
            cout << "Monthly pass used: no fare\n";
        } else if (card.pay(fare)) {
            cout << "Fare: " << fare << " paise\n";
        } else {
            cout << "Journey denied: minimum balance rule\n";
        }
        cout << "Balance: " << card.getBalance() << " paise\n";
    }
}
