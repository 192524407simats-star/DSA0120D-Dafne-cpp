#include <iostream>
#include <climits>
#include <limits>
using namespace std;

int main() {
    cout << "Data type sizes:\n";
    cout << "bool: " << sizeof(bool) << " byte(s)\n";
    cout << "char: " << sizeof(char) << " byte(s)\n";
    cout << "int: " << sizeof(int) << " byte(s)\n";
    cout << "unsigned int: " << sizeof(unsigned int) << " byte(s)\n";
    cout << "long long: " << sizeof(long long) << " byte(s)\n";
    cout << "float: " << sizeof(float) << " byte(s)\n";
    cout << "double: " << sizeof(double) << " byte(s)\n\n";

    cout << "INT_MIN: " << INT_MIN << '\n';
    cout << "INT_MAX: " << INT_MAX << '\n';
    cout << "LLONG_MIN: " << LLONG_MIN << '\n';
    cout << "LLONG_MAX: " << LLONG_MAX << '\n';

    long long journeys = 3000000;
    long long farePaise = 3000;
    long long totalPaise = journeys * farePaise;
    cout << "\nTotal for 3,000,000 journeys at Rs 30 each: "
         << totalPaise << " paise\n";

    int a = 7;
    double b = 2.5;
    double result = a + b;
    cout << "int + double = " << result << '\n';
}
