#include <iostream>
#include <string>
using namespace std;

class FareTable {
public:
    static constexpr long long INNER = 1000;
    static constexpr long long MIDDLE = 2000;
    static constexpr long long OUTER = 3000;

    long long getFare(int zone) const {
        switch (zone) {
            case 1: return INNER;
            case 2: return MIDDLE;
            case 3: return OUTER;
            default: return -1;
        }
    }
};

class Passenger {
protected:
    string name;
public:
    explicit Passenger(string n) : name(n) {}
    virtual int concessionPercent() const { return 0; }
    virtual ~Passenger() = default;
};

class Student : public Passenger {
public:
    explicit Student(string n) : Passenger(n) {}
    int concessionPercent() const override { return 10; }
};

class SeniorCitizen : public Passenger {
public:
    explicit SeniorCitizen(string n) : Passenger(n) {}
    int concessionPercent() const override { return 10; }
};

class SmartCard {
private:
    long long balance;
    static constexpr long long MIN_BALANCE = 5000;
public:
    explicit SmartCard(long long initial) : balance(initial) {}

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
    FareTable table;
    Student passenger("Student");
    SmartCard card(10000);

    int zone = 2;
    bool peak = true;
    long long fare = table.getFare(zone);

    if (fare < 0) {
        cout << "Invalid zone\n";
        return 0;
    }

    if (peak) fare += fare * 20 / 100;
    fare -= fare * passenger.concessionPercent() / 100;

    cout << "Passenger: Student\n";
    cout << "Fare: " << fare << " paise\n";
    if (card.deduct(fare))
        cout << "Journey allowed\n";
    else
        cout << "Journey denied\n";
    cout << "Balance: " << card.getBalance() << " paise\n";
}
