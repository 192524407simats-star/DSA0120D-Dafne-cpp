#include <iostream>
using namespace std;

class Event {
    int rows, seats;
    char** seatMap;
    int booked;

public:
    Event(int r, int s)
        : rows(r > 0 ? r : 0), seats(s > 0 ? s : 0),
          seatMap(nullptr), booked(0) {
        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];
            for (int i = 0; i < rows; ++i) {
                seatMap[i] = new char[seats];
                for (int j = 0; j < seats; ++j) seatMap[i][j] = 'O';
            }
        }
        cout << "Event created: " << rows << " x " << seats << '\n';
    }

    bool book(int r, int s) {
        if (!seatMap || r < 0 || r >= rows || s < 0 || s >= seats ||
            seatMap[r][s] == 'X') return false;
        seatMap[r][s] = 'X';
        ++booked;
        return true;
    }

    bool cancel(int r, int s) {
        if (!seatMap || r < 0 || r >= rows || s < 0 || s >= seats ||
            seatMap[r][s] == 'O') return false;
        seatMap[r][s] = 'O';
        --booked;
        return true;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < seats; ++j)
                cout << seatMap[i][j] << ' ';
            cout << '\n';
        }
    }

    ~Event() {
        if (seatMap) {
            for (int i = 0; i < rows; ++i) delete[] seatMap[i];
            delete[] seatMap;
        }
        cout << "Event closed. Seats booked: " << booked << '\n';
    }
};

int main() {
    Event localEvent(2, 3);
    localEvent.book(0, 1);
    localEvent.display();

    Event* heapEvent = new Event(2, 2);
    heapEvent->book(1, 1);
    delete heapEvent;

    {
        Event blockEvent(1, 2);
        blockEvent.book(0, 0);
    }

    Event zeroEvent(0, 5);
    return 0;
}
