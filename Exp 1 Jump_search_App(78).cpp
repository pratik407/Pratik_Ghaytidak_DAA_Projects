#include <stdio.h>
#include <math.h>

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

int jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    while(arr[(step < n ? step : n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if(prev >= n) {
            return -1;  
        }
    }

    while(prev < n && arr[prev] < key) {
        prev++;
        if(prev == (step < n ? step : n)) {
            return -1;
        }
    }

    if(arr[prev] == key) {
        return prev;
    }

    return -1;  
}

int main() {
    int n, i, key, pos;

    printf("Enter number of products: ");
    scanf("%d", &n);

    int productID[n];

    printf("Enter %d product id:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &productID[i]);
    }

    bubbleSort(productID, n);

    printf("\nSorted Product IDs: ");
    for(i = 0; i < n; i++) {
        printf("%d ", productID[i]);
    }
    printf("\n");

    printf("Enter Product ID to search: ");
    scanf("%d", &key);

    pos = jumpSearch(productID, n, key);

    if(pos != -1) {
        printf("Product ID %d found at position %d (in sorted list).\n", key, pos + 1);
    } else {
        printf("Product ID %d not found in the inventory.\n", key);
    }

    return 0;
}
