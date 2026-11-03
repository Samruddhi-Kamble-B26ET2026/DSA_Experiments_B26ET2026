#include <stdio.h>

// Recursive function to perform binary search
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential overflow

        // Key found at mid
        if (arr[mid] == key)
            return mid;

        // Key is smaller than mid, search left subarray
        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);

        // Key is larger than mid, search right subarray
        return binarySearch(arr, mid + 1, high, key);
    }

    // Key is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
