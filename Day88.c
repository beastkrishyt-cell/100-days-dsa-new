#include <stdio.h>
#include <stdlib.h>

// Day 88 - DSA Challenge: Aggressive Cows

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if we can place c cows with minimum distance 'dist'
int canPlaceCows(int arr[], int n, int c, int dist) {
    int count = 1; // place first cow at the first stall
    int lastPos = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPos >= dist) {
            count++;
            lastPos = arr[i];
            if (count == c) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n = 5; // Number of stalls
    int c = 3; // Number of cows
    int arr[] = {1, 2, 8, 4, 9}; // Stall locations
    
    // Step 1: Sort the stalls
    qsort(arr, n, sizeof(int), compare);
    
    // Step 2: Binary Search on the answer
    int low = 1;
    int high = arr[n - 1] - arr[0];
    int res = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canPlaceCows(arr, n, c, mid)) {
            res = mid;
            // Since we want the LARGEST minimum distance, we search in the right half
            low = mid + 1;
        } else {
            // We search in the left half
            high = mid - 1;
        }
    }
    
    printf("Largest minimum distance is %d\n", res);
    
    return 0;
}
