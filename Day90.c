#include <stdio.h>
#include <stdbool.h>

// Day 90 - DSA Challenge: Painter Partition Problem (Binary Search on Answer)

bool isPossible(int arr[], int n, int k, int timeLimit) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > timeLimit) return false;

        if (currTime + arr[i] > timeLimit) {
            painters++;
            currTime = arr[i];
            if (painters > k) return false;
        } else {
            currTime += arr[i];
        }
    }
    return true;
}

int painterPartition(int arr[], int n, int k) {
    int maxVal = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int low = maxVal;
    long long high = sum;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1; // Try to find a smaller maximum time
        } else {
            low = mid + 1; // We need more time
        }
    }

    return ans;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Number of painters

    printf("Minimum time to paint all boards: %d\n", painterPartition(arr, n, k));
    return 0;
}
