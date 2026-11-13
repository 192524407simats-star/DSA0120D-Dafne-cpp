#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title;
    string author;
    int copies;

public:
    Book() : Book("Untitled", "Unknown", 0) {}

    explicit Book(const string& t) : Book(t, "Unknown", 0) {}

    Book(const string& t, const string& a, int c)
        : title(t), author(a), copies(c < 0 ? 0 : c) {}

    void display() const {
        cout << "Title: " << title << ", Author: " << author
             << ", Copies: " << copies << '\n';
    }
};

int main() {
    Book empty;
    Book donated("Wings of Fire");
    Book complete("The Alchemist", "Paulo Coelho", 5);
    Book invalid("Invalid Book", "Unknown", -3);

    empty.display();
    donated.display();
    complete.display();
    invalid.display();
    return 0;
}
