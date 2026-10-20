#include <stdio.h>

int main() {
    int a[100], n, i, pos, val;


    printf("Enter size: ");
    scanf("%d", &n);


    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    printf("Enter value: ");
    scanf("%d", &val);

    if(pos < 1 || pos > n+1) {
        printf("Invalid position for insertion\n");
    } else {
        for(i = n; i >= pos; i--) {
            a[i] = a[i-1];
        }
        a[pos-1] = val;
        n++;
    }

    
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n) {
        printf("Invalid position for deletion\n");
    } else {
        for(i = pos-1; i < n-1; i++) {
            a[i] = a[i+1];
        }
        n--;
    }

  
    printf("Final array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}