
#include <iostream>
#include <vector>

using namespace std;

void gasStations(int d, int tc, int gs, vector<int>& gl) {
    int remainingDistance = d;
    int currentTank = tc;
    int stopsCount = 0;

    vector<int> stops;

    for (int i = 0; i < gs; ++i) {
        int ds = i == gs - 1 ? d - gl[i] : gl[i + 1] - gl[i];

        if (ds > currentTank) {
            if (stops.empty()) {
                cout << "Can't reach destination" << endl;
                return;
            }

            cout << stopsCount << endl;
            for (int stop : stops) {
                cout << stop << " ";
            }
            cout << endl;

            return;
        }

        if (ds > currentTank) {
            stops.push_back(gl[i]);
            currentTank = tc;
            stopsCount++;
        } else {
            currentTank -= ds;
        }
    }
}

int main() {
    int d, tc, gs;
    cin >> d >> tc >> gs;

    vector<int> gl(gs);
    for (int i = 0; i < gs; ++i) {
        cin >> gl[i];
    }

    gasStations(d, tc, gs, gl);

    return 0;
}
