#include <stdio.h>
#include<time.h>

void reverseInsertionSort(int arr[], int n) {
    for (int i = n - 2; i >= 0; i--) {
        int key = arr[i];
        int j = i + 1;
        
        while (j < n && arr[j] < key) {
            arr[j - 1] = arr[j];
            j++;
        }
        
        arr[j - 1] = key;
    }
}

int main() {
    int arr[] = {5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    reverseInsertionSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
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