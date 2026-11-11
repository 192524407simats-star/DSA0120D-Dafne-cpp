#include <iostream>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

double charge(double weightKg, bool express = false, bool insured = false) {
    double total = weightKg * 50.0;
    if (express) total += 40.0;
    if (insured) total += 20.0;
    return total;
}
double charge(int weightGrams) {
    return charge(static_cast<double>(weightGrams) / 1000.0, false, false);
}
double charge(const Parcel& p) {
    return charge(p.weightKg, p.express, p.insured);
}
int main() {
    Parcel p{2.0, true, true};
    cout << charge(500) << '\n';
    cout << charge(2.0) << '\n';
    cout << charge(2.0f) << '\n';
    cout << charge(2, true) << '\n';
    cout << charge(2.0, true) << '\n';
    cout << charge(p) << '\n';
}