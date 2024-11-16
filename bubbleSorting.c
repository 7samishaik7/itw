#include<stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

void printarr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("The element %d is: %d\n", i + 1, arr[i]);
    }
}

void bubble(int arr[], int size){
    for(int i=1;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
        
    }
    printarr(arr, size);
}

int main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    
    bubble(arr,size);
    time_t rawTime;
    struct tm *localTime;

    time(&rawTime);
    localTime = localtime(&rawTime);
    printf("Name : Mahammad Sami Shaik \n");
    printf("Roll No.: BT23CSE050\n");
    printf("Current local time: %s", asctime(localTime));

}