#include <cstring>
#include <iostream>
using namespace std;

class Text {
    char* data;

public:
    Text(const char* value = "") {
        data = new char[strlen(value) + 1];
        strcpy(data, value);
    }

    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    Text& operator=(const Text& other) {
        if (this != &other) {
            char* copy = new char[strlen(other.data) + 1];
            strcpy(copy, other.data);
            delete[] data;
            data = copy;
        }
        return *this;
    }

    Text& operator+=(const Text& other) {
        char* combined = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(combined, data);
        strcat(combined, other.data);
        delete[] data;
        data = combined;
        return *this;
    }

    friend Text operator+(const Text& a, const Text& b) {
        Text result(a);
        result += b;
        return result;
    }

    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const Text& value) {
        return out << value.data;
    }

    ~Text() { delete[] data; }
};

int main() {
    Text a("Hello "), b("World"), c("");
    Text message = a + b + c;
    cout << message << '\n';
    cout << boolalpha << (message != a) << '\n';

    message = message; // self-assignment test
    cout << message << '\n';
    return 0;
}
