#include <stdio.h>
#include <stdlib.h>

// Day 99 - DSA Challenge: Car Fleet Calculation

struct Car {
    int position;
    double timeToTarget;
};

int compareCars(const void* a, const void* b) {
    return ((struct Car*)b)->position - ((struct Car*)a)->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    struct Car* cars = (struct Car*)malloc(sizeof(struct Car) * positionSize);
    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].timeToTarget = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, positionSize, sizeof(struct Car), compareCars);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < positionSize; i++) {
        if (cars[i].timeToTarget > maxTime) {
            maxTime = cars[i].timeToTarget;
            fleets++;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    printf("Number of car fleets: %d\n", carFleet(target, position, n, speed, n));
    return 0;
}
