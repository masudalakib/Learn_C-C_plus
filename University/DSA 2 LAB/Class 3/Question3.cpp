//Write a function calc_sum using divide-and-conquer algorithm to calculate the sum of the even
//numbers of an array of n integers.

#include <iostream>

int calc_sum(const int Arr[], int i, int j) {
    if (i == j) {
        if (Arr[i] % 2 == 0)
            return Arr[i];
        else
            return 0;
    } else {
        int mid = (i + j) / 2;
        int c1 = calc_sum(Arr, i, mid);
        int c2 = calc_sum(Arr, mid + 1, j);
        return c1 + c2;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 4, 5,};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = calc_sum(arr, 0, n - 1);

    std::cout << "Sum of even numbers: " << sum << std::endl;

    return 0;
}

