#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    char id;
    int startTime;
    int duration;
    int endTime;
};

bool compareEvents(const Event& a, const Event& b) {
    return a.endTime < b.endTime;
}

int main() {
    int N;
    cin >> N;

    vector<Event> events(N);
    for (int i = 0; i < N; ++i) {
        cin >> events[i].id >> events[i].startTime >> events[i].duration;
        events[i].endTime = events[i].startTime + events[i].duration;
    }

    int cleanupTime;
    cin >> cleanupTime;

    // Sort events based on end times
    sort(events.begin(), events.end(), compareEvents);

    vector<char> chosenClubs;
    int currentTime = 0;

    // Choose events without conflicts
    for (const Event& event : events) {
        if (event.startTime >= currentTime) {
            chosenClubs.push_back(event.id);
            currentTime = event.endTime + cleanupTime;
        }
    }

    // Output the result
    cout << chosenClubs.size() << endl;
    for (const char& club : chosenClubs) {
        cout << club << " " << events[club - 'a'].startTime << " " << events[club - 'a'].endTime << endl;
    }

    return 0;
}
