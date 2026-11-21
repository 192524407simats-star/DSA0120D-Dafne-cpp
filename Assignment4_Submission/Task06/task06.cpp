#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented = false;
public:
    Vehicle(string r, double rate) : regNo(r), dailyRate(rate) {}
    virtual double charge(int days) const = 0;
    virtual string type() const = 0;
    virtual void rent() { rented = true; }
    virtual double returnVehicle(int daysLate) {
        rented = false;
        return daysLate * dailyRate * 1.5;
    }
    virtual void display() const {
        cout << type() << " " << regNo << " Rate/day: " << dailyRate
             << " Rented: " << (rented ? "Yes" : "No") << '\n';
    }
    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate) : Vehicle(r, rate) {}
    double charge(int days) const override { return days * dailyRate; }
    string type() const override { return "Bicycle"; }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDue;
public:
    MotorVehicle(string r, double rate, double fuel, string due)
        : Vehicle(r, rate), fuelLevel(fuel), serviceDue(due) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string r, double rate, double fuel, string due)
        : MotorVehicle(r, rate, fuel, due) {}
    double charge(int days) const override { return days * dailyRate; }
    string type() const override { return "TwoWheeler"; }
};

class Car : public MotorVehicle {
protected:
    int seats;
public:
    Car(string r, double rate, double fuel, string due, int s)
        : MotorVehicle(r, rate, fuel, due), seats(s) {}
    double charge(int days) const override { return days * dailyRate; }
    string type() const override { return "Car"; }
};

class ElectricCar : public Car {
    double batteryKWh;
    double pricePerKWh;
public:
    ElectricCar(string r, double rate, double fuel, string due, int s,
                double battery, double kwhRate)
        : Car(r, rate, fuel, due, s),
          batteryKWh(battery), pricePerKWh(kwhRate) {}
    double charge(int days) const override {
        return days * dailyRate + batteryKWh * pricePerKWh;
    }
    string type() const override { return "ElectricCar"; }
};

class ElectricBus : public Vehicle {
    int seats;
    double batteryKWh, pricePerKWh;
public:
    ElectricBus(string r, double rate, int s, double battery, double kwhRate)
        : Vehicle(r, rate), seats(s), batteryKWh(battery),
          pricePerKWh(kwhRate) {}
    double charge(int days) const override {
        return days * dailyRate + batteryKWh * pricePerKWh;
    }
    string type() const override { return "ElectricBus"; }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;
    fleet.push_back(make_unique<Bicycle>("BI-01", 100));
    fleet.push_back(make_unique<TwoWheeler>("TW-01", 250, 8, "2026-12-01"));
    fleet.push_back(make_unique<Car>("CA-01", 1000, 40, "2026-12-10", 5));
    fleet.push_back(make_unique<ElectricCar>("EV-01", 1200, 0, "2026-12-15",
                                             5, 60, 8));
    fleet.push_back(make_unique<ElectricBus>("EB-01", 3000, 30, 200, 8));

    for (const auto& v : fleet) {
        v->rent();
        v->display();
        cout << "Charge for 2 days: " << v->charge(2) << '\n';
        cout << "Late return fee (1 day): " << v->returnVehicle(1) << "\n\n";
    }
}
