#include <stdio.h>

struct Item {
    float weight, value, ratio;
};

int main() {
    int n;
    float capacity, totalValue = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter weight and value of item %d: ", i + 1);
        scanf("%f %f", &items[i].weight, &items[i].value);
        items[i].ratio = items[i].value / items[i].weight;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    printf("\nEnter truck capacity: ");
    scanf("%f", &capacity);

    float remaining = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remaining) {
            totalValue += items[i].value;
            remaining -= items[i].weight;
        } else {
            totalValue += items[i].ratio * remaining;
            break;
        }
    }

    printf("\nMaximum value that can be carried: %.2f\n", totalValue);

    return 0;
}
