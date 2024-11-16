#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    
    while (i < size1) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    
    while (j < size2) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}


int main() {
    int arr1[] = {13, 33, 52, 77};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {42, 84, 86, 98};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];

    
    mergeArrays(arr1, size1, arr2, size2, mergedArray);

    
    printf("Merged Array: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedArray[i]);
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

