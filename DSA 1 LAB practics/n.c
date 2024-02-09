#include <stdio.h>

int main() {
    int arr[] = {4, 5, 6, 5, 3, 6, 7, 8, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create an array to store frequency counts
    int counts[100] = {0};  // Assuming maximum element value is 99

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        counts[arr[i]]++;
    }

    // Sort the array directly using a custom sorting algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (counts[arr[j]] > counts[arr[i]]) {
                // Swap elements and their corresponding counts
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                temp = counts[arr[i]];
                counts[arr[i]] = counts[arr[j]];
                counts[arr[j]] = temp;
            } else if (counts[arr[j]] == counts[arr[i]] && arr[j] < arr[i]) {
                // Break ties based on element values (smaller elements first)
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
