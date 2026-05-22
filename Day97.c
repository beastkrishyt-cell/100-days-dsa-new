#include <stdio.h>
#include <stdlib.h>

// Day 97 - DSA Challenge: Meeting Rooms Scheduling

struct Interval {
    int start;
    int end;
};

int compare(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

int canAttendAllMeetings(struct Interval* intervals, int size) {
    if (size == 0) return 1;

    qsort(intervals, size, sizeof(struct Interval), compare);

    for (int i = 1; i < size; i++) {
        if (intervals[i].start < intervals[i - 1].end) {
            return 0; // Overlapping meeting found
        }
    }
    return 1;
}

int main() {
    struct Interval meetings1[] = {{0, 30}, {5, 10}, {15, 20}};
    int n1 = sizeof(meetings1) / sizeof(meetings1[0]);
    printf("Can attend all meetings 1? %s\n", canAttendAllMeetings(meetings1, n1) ? "Yes" : "No");

    struct Interval meetings2[] = {{7, 10}, {2, 4}};
    int n2 = sizeof(meetings2) / sizeof(meetings2[0]);
    printf("Can attend all meetings 2? %s\n", canAttendAllMeetings(meetings2, n2) ? "Yes" : "No");

    return 0;
}
