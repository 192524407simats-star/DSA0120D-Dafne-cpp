#include <iostream>
#include <string>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    explicit Prescription(int count)
        : n(count < 0 ? 0 : count),
          medicines(new string[n]) {}

    Prescription(const Prescription& other)
        : n(other.n), medicines(new string[other.n]) {
        for (int i = 0; i < n; ++i)
            medicines[i] = other.medicines[i];
    }

    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            string* newMedicines = new string[other.n];
            for (int i = 0; i < other.n; ++i)
                newMedicines[i] = other.medicines[i];
            delete[] medicines;
            medicines = newMedicines;
            n = other.n;
        }
        return *this;
    }

    ~Prescription() {
        delete[] medicines;
    }

    void set(int i, const string& medicine) {
        if (i >= 0 && i < n) medicines[i] = medicine;
    }

    string get(int i) const {
        return (i >= 0 && i < n) ? medicines[i] : "Invalid index";
    }
};

int main() {
    Prescription p(2);
    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;
    q.set(1, "Cetirizine");

    Prescription r(1);
    r = p;

    p.set(0, "Ibuprofen");

    cout << p.get(0) << ' ' << p.get(1) << " | "
         << q.get(0) << ' ' << q.get(1) << " | "
         << r.get(0) << ' ' << r.get(1) << '\n';
    return 0;
}
