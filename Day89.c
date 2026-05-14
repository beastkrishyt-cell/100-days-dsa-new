#include <stdio.h>
#include <stdbool.h>

// Day 89 - DSA Challenge: Allocate Minimum Number of Pages

// Function to check if a current minimum page limit allows valid allocation
bool isPossible(int arr[], int n, int m, int curr_min) {
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > curr_min)
            return false; // A single book has more pages than the limit

        if (curr_sum + arr[i] > curr_min) {
            // Allocate to next student
            studentsRequired++;
            curr_sum = arr[i];

            if (studentsRequired > m)
                return false;
        } else {
            curr_sum += arr[i];
        }
    }
    return true;
}

// Function to find the minimum of the maximum number of pages
int findPages(int arr[], int n, int m) {
    if (n < m)
        return -1; // Not enough books to allocate at least one to each student

    long long sum = 0;
    int max_val = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int start = max_val;
    long long end = sum;
    int result = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid; // Valid allocation, try to find a smaller maximum
            end = mid - 1;
        } else {
            start = mid + 1; // Not valid, we need a larger limit
        }
    }

    return result;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2; // Number of students

    printf("Array of books: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of students: %d\n", m);

    int result = findPages(arr, n, m);
    if (result != -1) {
        printf("Minimum number of pages = %d\n", result);
    } else {
        printf("Allocation is not possible.\n");
    }

    return 0;
}
