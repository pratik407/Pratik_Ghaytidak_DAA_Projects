#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);

    int size[n];
    printf("Enter sizes of %d files:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &size[i]);

    int totalCost = 0;
    sort(size, n);

    while (n > 1) {
        int first = size[0];
        int second = size[1];
        int mergeCost = first + second;
        totalCost += mergeCost;

        for (int i = 2; i < n; i++)
            size[i - 2] = size[i];

        size[n - 2] = mergeCost;
        n--;

        sort(size, n);
    }

    printf("\nMinimum total cost for merging files: %d\n", totalCost);
    return 0;
}
