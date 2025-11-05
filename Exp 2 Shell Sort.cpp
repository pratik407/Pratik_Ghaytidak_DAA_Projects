#include <stdio.h>

int main() {
    int n, i, j, gap, temp;
    printf("Enter number of students: ");
    scanf("%d", &n);

    int marks[n];
    for(i = 0; i < n; i++) {
        printf("Enter marks of student %d: ", i+1);
        scanf("%d", &marks[i]);
    }

    for(gap = n/2; gap > 0; gap /= 2) {
        for(i = gap; i < n; i++) {
            temp = marks[i];
            j = i;
            while(j >= gap && marks[j-gap] > temp) {
                marks[j] = marks[j-gap];
                j -= gap;
            }
            marks[j] = temp;
        }
    }

    printf("\nMarks in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    return 0;
}
