#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;
public:
    Person(string n, int i, string p) : name(n), id(i), phone(p) {
        cout << "Person ";
    }
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;
public:
    Student(string n, int i, string p, string pr, double c)
        : Person(n, i, p), programme(pr), cgpa(c) { cout << "Student "; }
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;
public:
    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p), department(d), salary(s) { cout << "Staff "; }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p, string pr, double c,
                      string d, double s)
        : Person(n, i, p), Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) { cout << "TA "; }
    void print() const {
        cout << "\n" << name << " " << id << " " << phone << " "
             << programme << " " << cgpa << " " << department << " " << salary << '\n';
    }
};

class ResearchScholar : public Student {
    double fellowship;
public:
    ResearchScholar(string n, int i, string p, string pr, double c, double f)
        : Person(n, i, p), Student(n, i, p, pr, c), fellowship(f) {}
};

int main() {
    TeachingAssistant ta("Kavya", 10, "9876543210", "AI&DS", 8.7,
                         "CSE", 25000);
    ta.print();
}
