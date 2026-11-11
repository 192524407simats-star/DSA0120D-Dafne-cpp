#include <iostream>
using namespace std;

void concessionByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
    cout << "Inside value function: " << fee << '\n';
}
void concessionByReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}
void concessionByPointer(long long* fee, int percent) {
    if (fee != nullptr)
        *fee -= (*fee) * percent / 100;
}
int main() {
    long long a = 45000, b = 45000, c = 45000;
    concessionByValue(a, 10);
    concessionByReference(b, 10);
    concessionByPointer(&c, 10);
    cout << "Stored fee after value     : " << a << '\n';
    cout << "Stored fee after reference : " << b << '\n';
    cout << "Stored fee after pointer   : " << c << '\n';
    return 0;
}