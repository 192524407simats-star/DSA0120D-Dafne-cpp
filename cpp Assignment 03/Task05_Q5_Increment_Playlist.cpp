#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Time {
    int seconds;

public:
    explicit Time(int total = 0) : seconds(total < 0 ? 0 : total) {}

    Time& operator++() {
        ++seconds;
        return *this;
    }

    Time operator++(int) {
        Time old = *this;
        ++seconds;
        return old;
    }

    bool operator==(const Time& other) const {
        return seconds == other.seconds;
    }

    bool operator<(const Time& other) const {
        return seconds < other.seconds;
    }

    void display() const {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;
        cout << h << ':' << (m < 10 ? "0" : "") << m
             << ':' << (s < 10 ? "0" : "") << s;
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist(initializer_list<string> items) : tracks(items) {}

    string& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");
        return tracks[index];
    }

    const string& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");
        return tracks[index];
    }

    int size() const { return static_cast<int>(tracks.size()); }
};

int main() {
    Time t(3599);
    Time a = t++;
    Time b = ++t;
    cout << "a = "; a.display();
    cout << "\nb = "; b.display();
    cout << "\nt = "; t.display();
    cout << '\n';

    Playlist playlist{"Track One", "Track Two", "Track Three"};
    cout << playlist[0] << '\n';
    try {
        cout << playlist[playlist.size()] << '\n';
    } catch (const out_of_range& e) {
        cout << e.what() << '\n';
    }
    return 0;
}
