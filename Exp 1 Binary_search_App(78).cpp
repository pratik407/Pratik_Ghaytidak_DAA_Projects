#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i, key, low, high, mid, flag = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    int roll_no[n];

    printf("Enter %d roll numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &roll_no[i]);
    }

    bubbleSort(roll_no, n);
    printf("\n");

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(roll_no[mid] == key) {
            printf("Roll number %d found at position %d (in sorted list)\n", key, mid + 1);
            flag = 1;
            break;
        }
        else if(roll_no[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(flag == 0) {
        printf("Roll number %d not found in the list.\n", key);
    }

    return 0;
}
