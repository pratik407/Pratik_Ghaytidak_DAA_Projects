#include <stdio.h>

int main() {
    int n, i, j, key;
    printf("Enter number of students: ");
    scanf("%d", &n);

    int roll[n];

    for(i = 0; i < n; i++) {
        printf("Enter roll number of student %d: ", i+1);
        scanf("%d", &roll[i]);
    }

    for(i = 1; i < n; i++) {
        key = roll[i];
        j = i - 1;
        while(j >= 0 && roll[j] > key) {
            roll[j+1] = roll[j];
            j = j - 1;
        }
        roll[j+1] = key;
    }

    printf("\nRoll numbers in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", roll[i]);
    }

    return 0;
}
