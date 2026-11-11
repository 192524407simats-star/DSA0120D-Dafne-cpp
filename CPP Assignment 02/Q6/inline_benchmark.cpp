#include <iostream>
#include <chrono>
using namespace std;

volatile long long sink = 0;

inline int inlineAdd(int a, int b) { return a + b; }

#if defined(__GNUC__) || defined(__clang__)
__attribute__((noinline))
#endif
int ordinaryAdd(int a, int b) { return a + b; }

int main() {
    const int N = 10000000;
    auto start = chrono::high_resolution_clock::now();
    long long sum = 0;
    for (int i = 0; i < N; ++i) sum += inlineAdd(i, 2);
    sink = sum;
    auto mid = chrono::high_resolution_clock::now();

    sum = 0;
    for (int i = 0; i < N; ++i) sum += ordinaryAdd(i, 2);
    sink = sum;
    auto end = chrono::high_resolution_clock::now();

    cout << "inline ns: "
         << chrono::duration_cast<chrono::nanoseconds>(mid - start).count() << '\n';
    cout << "ordinary ns: "
         << chrono::duration_cast<chrono::nanoseconds>(end - mid).count() << '\n';
}