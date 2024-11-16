#include<stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
        printf("\n");
    }

    for(int i=1;i<size;i++){
        int temp=arr[i];
        int j=i-1;
        while(arr[j]>temp && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    for(int i = 0; i < size; i++) {
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