#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}
void applyConcession(long long& fee, int percent) {
    fee -= fee * percent / 100; // TODO 1 completed
}
int main() {
    long long hostelFee = 45000;
    applyByValue(hostelFee, 10);
    cout << "after call by value   : " << hostelFee << '\n';
    applyConcession(hostelFee, 10);
    cout << "after call by reference: " << hostelFee << '\n';
}