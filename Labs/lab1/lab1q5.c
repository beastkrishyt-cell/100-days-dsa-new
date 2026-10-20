#include <stdio.h>
int main() {
    int r1, c1, r2, c2, i, j, k;
    printf("Enter rows and cols of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    if(c1 != r2) {
        printf("Multiplication not possible\n");
        return 0;
    }
    int A[r1][c1], B[r2][c2], C[r1][c2];
    printf("Enter Matrix A:\n");
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c1; j++) {
            scanf("%d", (*(A+i)+j));   // pointer style
        }
    }
    printf("Enter Matrix B:\n");
    for(i = 0; i < r2; i++) {
        for(j = 0; j < c2; j++) {
            scanf("%d", (*(B+i)+j));   // pointer style
        }
    }
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            *(*(C+i)+j) = 0;
            for(k = 0; k < c1; k++) {
                *(*(C+i)+j) += (*(*(A+i)+k)) * (*(*(B+k)+j));
            }
        }
    }
    printf("\nResult Matrix:\n");
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            printf("%d ", *(*(C+i)+j));
        }
        printf("\n");
    }
    return 0;
}