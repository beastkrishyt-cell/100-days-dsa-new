#include <stdio.h>
#include <string.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char names[1000][50];
    int votes[1000] = {0};
    int numCandidates = 0;
    for (int i = 0; i < n; i++) {
        char vote[50]; scanf("%49s", vote);
        int found = 0;
        for (int j = 0; j < numCandidates; j++) {
            if (strcmp(names[j], vote) == 0) {
                votes[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(names[numCandidates], vote);
            votes[numCandidates] = 1;
            numCandidates++;
        }
    }
    int maxVotes = 0;
    for (int i = 0; i < numCandidates; i++) {
        if (votes[i] > maxVotes) maxVotes = votes[i];
    }
    char winner[50] = "";
    for (int i = 0; i < numCandidates; i++) {
        if (votes[i] == maxVotes) {
            if (strlen(winner) == 0 || strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }
    printf("%s %d\n", winner, maxVotes);
    return 0;
}
