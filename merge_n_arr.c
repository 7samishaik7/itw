#include <stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

void mergeNArrays(int* arrays[], int sizes[], int n, int result[]) {
    int currentIndex[n];
    for (int i = 0; i < n; i++) {
        currentIndex[i] = 0;
    }

    int mergedSize = 0;

    for (int i = 0; i < n; i++) {
        mergedSize += sizes[i];
    }

    int i = 0;

    while (i < mergedSize) {
        int minValue = 2147483647; // Maximum positive value for a 32-bit integer
        int minIndex = -1;

        for (int j = 0; j < n; j++) {
            if (currentIndex[j] < sizes[j] && arrays[j][currentIndex[j]] <= minValue) {
                minValue = arrays[j][currentIndex[j]];
                minIndex = j;
            }
        }

        if (minIndex != -1) {
            result[i] = minValue;
            currentIndex[minIndex]++;
            i++;
        }
    }
}

int main() {
    
    int arr1[] = {1, 5, 9, 13};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 6, 10, 14};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {3, 7, 11, 15};
    int size3 = sizeof(arr3) / sizeof(arr3[0]); 

    int arr4[] = {10, 44, 88, 122, 166};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);

    int* arrays[] = {arr1, arr2, arr3, arr4};
    int sizes[] = {size1, size2, size3, size4};
    int n = sizeof(arrays) / sizeof(arrays[0]);
 
    int mergedSize = size1 + size2 + size3 + size4;
    int mergedArray[mergedSize];

    mergeNArrays(arrays, sizes, n, mergedArray);

    printf("Merged Array: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");
    time_t rawTime;
    struct tm *localTime;

    time(&rawTime);
    localTime = localtime(&rawTime);
    printf("Name : Mahammad Sami Shaik \n");
    printf("Roll No.: BT23CSE050\n");
    printf("Current local time: %s", asctime(localTime));

    return 0;
}
