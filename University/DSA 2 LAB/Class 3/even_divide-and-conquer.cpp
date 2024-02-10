#include<iostream>
using namespace std;
int countEven(int Arr[], int i, int j) {
    if (i == j) {
        if (Arr[i] % 2 == 0)
            return 1;
        else
            return 0;
    } else {
        int mid = (i + j) / 2;
        int c1 = countEven(Arr, i, mid);
        int c2 = countEven(Arr, mid + 1, j);
        return c1 + c2;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 12, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int count = countEven(arr, 0, n - 1);
    std::cout << "Count of even numbers: " << count << std::endl;

    return 0;
}
