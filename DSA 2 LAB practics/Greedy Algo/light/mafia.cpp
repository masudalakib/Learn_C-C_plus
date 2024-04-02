#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumMoves(int n, const vector<vector<int>>& graph) {
  vector<int> outDegrees(n, 0); // Count outgoing edges for each city

  // Calculate out-degrees (number of adjacent cities) for each city
  for (int v = 0; v < n; ++v) {
    for (int neighbor : graph[v]) {
      outDegrees[neighbor]++;
    }
  }

  // Initialize a queue with cities that have no incoming edges (leaves)
  queue<int> leaves;
  for (int v = 0; v < n; ++v) {
    if (outDegrees[v] == 0) {
      leaves.push(v);
    }
  }

  int moves = 0;
  int processed = 0; // Count of processed cities

  while (!leaves.empty()) {
    int numLeaves = leaves.size(); // Number of leaves to process in this level

    // Process all leaves in the current level
    while (numLeaves-- > 0) {
      int city = leaves.front();
      leaves.pop();
      processed++;

      // Move mafia boy from this city to an adjacent city
      for (int neighbor : graph[city]) {
        outDegrees[neighbor]--;
        if (outDegrees[neighbor] == 0) {
          leaves.push(neighbor);
        }
      }
    }

    moves++; // Increment moves after processing a level of leaves
  }

  // Check if all cities are processed (guarded)
  return (processed == n) ? moves : -1; // -1 if unreachable
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
      int v, numBoys, d;
      cin >> v >> numBoys >> d;

      // Read adjacent cities (excluding the parent)
      for (int j = 0; j < d; ++j) {
        int neighbor;
        cin >> neighbor;
        graph[v].push_back(neighbor);
      }
    }

    int moves = minimumMoves(n, graph);
    cout << "Case " << t << ": ";
    if (moves != -1) {
      cout << moves << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }

  return 0;
}

