#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    int totalMinutes() const { return h * 60 + m; }
    int minutesTo(const Time& other) const {
        return abs(totalMinutes() - other.totalMinutes());
    }
    bool isEarlier(const Time& other) const {
        return totalMinutes() < other.totalMinutes();
    }
};
int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << departure.minutesTo(arrival) << ' '
         << boolalpha << arrival.isEarlier(departure) << '\n';
}