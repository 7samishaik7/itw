#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
int merge(int arr[], int size, int low, int mid, int high)
{

    int b[size];
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            b[k] = arr[j];
            j++;
            k++;
        }
        else if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}

int mergesort(int arr[], int size, int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
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
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
        printf("\n");
    }

    mergesort(arr, size, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("The element %d is: %d\n", i + 1, arr[i]);
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