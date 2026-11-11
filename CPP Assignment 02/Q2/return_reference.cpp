#include <iostream>
using namespace std;

int& highestMark(int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}

// Do not call this function: it returns a dangling reference.
int& invalidReference() {
    int value = 50;
    return value; // Deliberately unsafe example for compiler-warning study
}

int highestIndex(const int a[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (a[i] > a[best]) best = i;
    return best;
}
int* highestPointer(int a[], int n) {
    int* best = &a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > *best) best = &a[i];
    return best;
}
int main() {
    int marks[] = {76, 91, 84, 88, 69};
    highestMark(marks, 5) += 2;
    for (int x : marks) cout << x << ' ';
    cout << '\n';

    int index = highestIndex(marks, 5);
    marks[index] += 1;
    *highestPointer(marks, 5) += 1;
    cout << "After index and pointer updates: ";
    for (int x : marks) cout << x << ' ';
    cout << '\n';
}