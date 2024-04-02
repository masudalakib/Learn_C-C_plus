
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void smallestUnitLengthIntervals(vector<double>& points) {
    sort(points.begin(), points.end());

    vector<double> result;
    double currentIntervalStart = points[0];
    double currentIntervalEnd = currentIntervalStart + 1.0;

    result.push_back(currentIntervalStart);
    result.push_back(currentIntervalEnd);

    for (int i = 1; i < points.size(); ++i) {
        if (points[i] > currentIntervalEnd) {
            currentIntervalStart = points[i];
            currentIntervalEnd = currentIntervalStart + 1.0;
            result.push_back(currentIntervalStart);
            result.push_back(currentIntervalEnd);
        }
    }

    cout << result.size() / 2 << endl;
    for (double value : result) {
        cout << value << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<double> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    smallestUnitLengthIntervals(points);

    return 0;
}
