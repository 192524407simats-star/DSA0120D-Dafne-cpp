#include <iomanip>
#include <iostream>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    Money operator+(const Money& other) const {
        long long total = paise + other.paise;
        return Money(total / 100, static_cast<int>(total % 100));
    }

    Money operator-(const Money& other) const {
        long long total = paise - other.paise;
        return Money(total / 100, static_cast<int>(total % 100));
    }

    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }

    bool operator==(const Money& other) const {
        return paise == other.paise;
    }

    bool operator<(const Money& other) const {
        return paise < other.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        long long absolute = (m.paise < 0) ? -m.paise : m.paise;
        if (m.paise < 0) out << "-";
        out << "Rs " << absolute / 100 << '.'
            << setw(2) << setfill('0') << absolute % 100
            << setfill(' ');
        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;
        if (in >> rupees >> p) m.paise = rupees * 100 + p;
        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;
    cout << c << '\n' << boolalpha << (c == Money(200)) << '\n';

    Money x(0, 75), y(0, 50);
    cout << x + y << '\n';
    cout << Money(2, 0) - Money(3, 25) << '\n';
    return 0;
}
