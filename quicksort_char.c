#include <stdio.h>
#include<time.h>
#include<stdbool.h>

    void swap(char* a, char* b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(char arr[], int low, int high) {
        char pivot = arr[low];
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }

        swap(&arr[low], &arr[j]);
        return j;
    }

    void quickSort(char arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    int main() {
        char arr[100];
        int n;

        printf("Enter the number of elements: ");
        scanf("%d", &n);

        printf("Enter the elements: ");
        for (int i = 0; i < n; i++) {
            scanf(" %c", &arr[i]);
        }

        printf("Original array: ");
        for (int i = 0; i < n; i++) {
            printf("%c ", arr[i]);
        }
        printf("\n");

        quickSort(arr, 0, n - 1);

        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%c ", arr[i]);
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