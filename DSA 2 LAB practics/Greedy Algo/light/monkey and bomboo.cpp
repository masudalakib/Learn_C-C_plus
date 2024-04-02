#include <iostream>
#include <vector>

using namespace std;

int minimumStrength(int n, const vector<int>& heights) {
  int k = 0; // Minimum strength factor
  int current = 0; // Current position (height)

  for (int i = 0; i < n; ++i) {
    int jump = heights[i] - current; // Distance to next rung
    k = max(k, jump); // Update k if the jump is greater than current k
    current = heights[i]; // Update current position
  }

  return k;
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
      cin >> heights[i];
    }

    int k = minimumStrength(n, heights);
    cout << "Case " << t << ": " << k << endl;
  }

  return 0;
}
