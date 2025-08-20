#include <stdio.h>
#include <limits.h>

void findSecondAndThirdLargest(int arr[], int n) {
    if (n < 3) {
        printf("Array must have at least three elements.\n");
        return;
    }

    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != second && arr[i] != first) {
            third = arr[i];
        }
    }

    if (third == INT_MIN) {
        printf("There is no third largest element.\n");
    } else {
        printf("The second largest number is %d\n", second);
        printf("The third largest number is %d\n", third);
    }
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findSecondAndThirdLargest(arr, n);
    return 0;
}
