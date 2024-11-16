#include <stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

void removeDuplicates(int arr[], int *size) {
    int newSize = 0;

    for (int i = 0; i < *size; i++) {
        int isDuplicate = 0;

        // Check if the current element is a duplicate
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        // If not a duplicate, add it to the new array
        if (!isDuplicate) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    *size = newSize; // Update the size of the array
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    removeDuplicates(arr, &size);

    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    time_t rawTime;
    struct tm *localTime;

    time(&rawTime);
    localTime = localtime(&rawTime);
    printf("Name : Mahammad Sami Shaik \n");
    printf("Roll No.: BT23CSE050\n");
    printf("Current local time: %s", asctime(localTime));

    return 0;
}
