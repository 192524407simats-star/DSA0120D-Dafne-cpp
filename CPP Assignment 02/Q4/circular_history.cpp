#include <iostream>
using namespace std;

class TransactionHistory {
    static const int CAPACITY = 50;
    double data[CAPACITY];
    int count = 0;
    int next = 0;

public:
    void add(double amount) {
        data[next] = amount;
        next = (next + 1) % CAPACITY;
        if (count < CAPACITY) ++count;
    }
    void print() const {
        int oldest = (next - count + CAPACITY) % CAPACITY;
        for (int i = 0; i < count; ++i) {
            int index = (oldest + i) % CAPACITY;
            cout << data[index] << '\n';
        }
    }
};
int main() {
    TransactionHistory history;
    for (int i = 1; i <= 55; ++i) history.add(i * 10);
    history.print();
}