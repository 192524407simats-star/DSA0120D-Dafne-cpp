#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(const string& n, int a) : name(n), age(a) {
        cout << "Person+ ";
    }
    virtual ~Person() { cout << "Person- "; }
};

class Address {
    string city;
    int pin;
public:
    Address(const string& c, int p) : city(c), pin(p) {
        cout << "Address+ ";
    }
    ~Address() { cout << "Address- "; }
    string str() const { return city + "-" + to_string(pin); }
};

class Course {
    string title;
public:
    Course(const string& t) : title(t) { cout << "Course+ "; }
    ~Course() { cout << "Course- "; }
};

class Student : public Person {
    long long regNo;
    Address home;
    Course course;
public:
    Student(const string& n, int a, long long r, const string& city,
            int pin, const string& c)
        : Person(n, a), regNo(r), home(city, pin), course(c) {
        cout << "Student+ ";
    }
    ~Student() { cout << "Student- "; }
    void print() const {
        cout << "\n" << regNo << " " << name << " (" << age << ") "
             << home.str() << '\n';
    }
};

int main() {
    Student s("Kavya", 19, 192311001, "Salem", 636001, "OOP");
    s.print();
}
