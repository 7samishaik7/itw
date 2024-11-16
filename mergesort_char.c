#include <stdio.h>
#include <time.h>
#include<stdbool.h>

void merge(char arr[], int size, int low, int mid, int high)
{
    char b[size];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
            b[k++] = arr[j++];
        else
            b[k++] = arr[i++];
    }

    while (i <= mid)
        b[k++] = arr[i++];

    while (j <= high)
        b[k++] = arr[j++];

    for (int i = low; i <= high; i++)
        arr[i] = b[i];
}

void mergesort(char arr[], int size, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, size, low, mid);
        mergesort(arr, size, mid + 1, high);
        merge(arr, size, low, mid, high);
    }
}

int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    getchar(); 
    char arr[size];

    printf("Enter the characters: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%c", &arr[i]);
        
    }

    mergesort(arr, size, 0, size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
        printf("%c ", arr[i]);
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
