#include<stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
void printarr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("The element %d is: %d\n", i + 1, arr[i]);
    }
}

void insert(int arr[], int *size) {
    int index;

    do {
        printf("Enter the element index where you want to insert: ");
        scanf("%d", &index);
    } while(index < 0 || index > *size);

    (*size)++; 

    for(int i = *size - 1; i >= index; i--) {
        arr[i] = arr[i - 1];
    }

    printf("Enter the element you want to insert: ");
    int ele;
    scanf("%d", &ele);
    arr[index-1] = ele;
    printf("Array after insertion:\n");
    printarr(arr, *size);
}


void delete(int arr[],int *size){

    int index;
    printf("Enter the index of the element which you want to delete : ");
    scanf("%d",&index);
    
    for(int i= index-1;i<*size;i++){
        arr[i]=arr[i+1];

    }
    (*size)--;
    printarr(arr, *size);

}

int linearsearch(int arr[],int *size){
    int key;
    printf("Enter the element you want to search : ");
    scanf("%d",&key);
    for(int i=0;i<*size;i++){
        if(arr[i]==key)
        return i;
    }
    return -1;
}

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
        printf("\n");
    }

    
    int i;

    int opt;
    do{

    printf("Enter an option provided below : \n");
    printf("1.Inserting an element at specific position.\n");
    printf("2.Deleting element at a specific position.\n");
    printf("3. Perform linear search.\n");
    printf("4. Exit\n");

    

    scanf("%d",&opt);

    switch (opt)
    {
    case 1 : insert(arr, &size);
        break;
    
    case 2 : delete(arr, &size);
        break;

    case 3 : i=linearsearch(arr, &size);
        if(i==-1)
        printf("The element is not found !!");
        else
        printf("The element is found at index %d",i+1);
        break;

    case 4:
                printf("Exiting program.\n");
                break;

     default:
        printf("Invalid option. Please try again.\n");    

    
    }

}while(opt!=4);

time_t rawTime;
    struct tm *localTime;

    time(&rawTime);
    localTime = localtime(&rawTime);
    printf("Name : Mahammad Sami Shaik \n");
    printf("Roll No.: BT23CSE050\n");
    printf("Current local time: %s", asctime(localTime));


    return 0;
}
