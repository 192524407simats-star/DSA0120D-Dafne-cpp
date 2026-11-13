#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(double r) : real(r), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& z) const {
        return Complex(real + z.real, imag + z.imag);
    }

    Complex operator-(const Complex& z) const {
        return Complex(real - z.real, imag - z.imag);
    }

    Complex operator*(const Complex& z) const {
        return Complex(real * z.real - imag * z.imag,
                       real * z.imag + imag * z.real);
    }

    Complex operator/(const Complex& z) const {
        double denominator = z.real * z.real + z.imag * z.imag;
        if (denominator == 0.0)
            throw runtime_error("Division by zero impedance");
        return Complex((real * z.real + imag * z.imag) / denominator,
                       (imag * z.real - real * z.imag) / denominator);
    }

    bool operator==(const Complex& z) const {
        const double eps = 1e-9;
        return fabs(real - z.real) < eps && fabs(imag - z.imag) < eps;
    }

    double magnitude() const { return sqrt(real * real + imag * imag); }

    friend ostream& operator<<(ostream& out, const Complex& z) {
        out << z.real;
        if (z.imag >= 0) out << " + j" << z.imag;
        else out << " - j" << -z.imag;
        return out;
    }
};

int main() {
    const double pi = acos(-1.0);
    double frequency = 50.0, inductance = 0.1, capacitance = 100e-6;
    double omega = 2.0 * pi * frequency;

    Complex resistor(10.0, 0.0);
    Complex inductor(0.0, omega * inductance);
    Complex capacitor(0.0, -1.0 / (omega * capacitance));

    Complex series = resistor + inductor + capacitor;
    Complex parallel = (resistor * inductor) / (resistor + inductor);

    cout << "Resistor: " << resistor << '\n';
    cout << "Inductor: " << inductor << '\n';
    cout << "Capacitor: " << capacitor << '\n';
    cout << "Series impedance: " << series << '\n';
    cout << "Series magnitude: " << series.magnitude() << '\n';
    cout << "Parallel (R and L): " << parallel << '\n';

    try {
        Complex invalid = resistor / Complex();
        cout << invalid << '\n';
    } catch (const runtime_error& e) {
        cout << e.what() << '\n';
    }
    return 0;
}
