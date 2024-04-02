#include <iostream>
#include <vector>

using namespace std;

void generateGrid(int m, int n, vector<int>& phase1Sum, vector<int>& phase2Sum) {
    vector<vector<int>> grid(m, vector<int>(n, 0));

    int p1Index = 0, p2Index = 0;

    // Fill the grid based on phase 1 sum
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = phase1Sum[p1Index++];
        }
    }

    // Fill the remaining cells based on phase 2 sum
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                grid[i][j] = phase2Sum[p2Index++];
            }
        }
    }

    // Print the generated grid
    cout << "Case 1:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j];
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int m, n;
        cin >> m >> n;

        vector<int> phase1Sum(n + m - 1);
        vector<int> phase2Sum(n + m - 1);

        for (int i = 0; i < n + m - 1; ++i) {
            cin >> phase1Sum[i];
        }

        for (int i = 0; i < n + m - 1; ++i) {
            cin >> phase2Sum[i];
        }

        generateGrid(m, n, phase1Sum, phase2Sum);
    }

    return 0;
}
