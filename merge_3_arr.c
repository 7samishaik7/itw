#include <stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

void mergeThreeArrays(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3, int result[]) {
    int i = 0, j = 0, k = 0, l = 0;

    while (i < size1 && j < size2 && k < size3) {
        if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
            result[l] = arr1[i];
            i++;
        } else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) {
            result[l] = arr2[j];
            j++;
        } else {
            result[l] = arr3[k];
            k++;
        }
        l++;
    }

    while (i < size1) {
        result[l] = arr1[i];
        i++;
        l++;
    }

    while (j < size2) {
        result[l] = arr2[j];
        j++;
        l++;
    }

    while (k < size3) {
        result[l] = arr3[k];
        k++;
        l++;
    }
}

int main() {
    int arr1[] = {1, 4, 7, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 5, 8, 11};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {3, 6, 9, 12};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    int mergedSize = size1 + size2 + size3;
    int mergedArray[mergedSize];

    mergeThreeArrays(arr1, size1, arr2, size2, arr3, size3, mergedArray);

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
