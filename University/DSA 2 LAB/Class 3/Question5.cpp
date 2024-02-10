#include<iostream>
using namespace std;

struct Res {
    float max;
    float min;
};

Res findMaxMin(float A[], int i, int j) {
    Res result;

    if (i == j) {
        result.max = A[i];
        result.min = A[i];
    } else {
        int mid = (i + j) / 2;
        Res res1 = findMaxMin(A, i, mid);
        Res res2 = findMaxMin(A, mid + 1, j);

        result.max = max(res1.max, res2.max);
        result.min = min(res1.min, res2.min);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    float arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Res result = findMaxMin(arr, 0, n - 1);

    cout << "max: " << result.max << endl;
    cout << "min: " << result.min << endl;

    return 0;
}
