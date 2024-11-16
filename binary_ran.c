.#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
 
// generating random number
int random(int s, int e){
    srand(time(NULL));
    int randomNumber = rand() % (e - s + 1) + s;
    return randomNumber;
 
}
 
// for sorting
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
 
//print array
void printarr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("The element %d is: %d\n", i + 1, arr[i]);
    }
}
 
// the search
int bin(int arr[], int size, int key){
 
    int s=0;
    int e=size;
    while(s<=e){
        int mid=random(s,e);
        if(key==arr[mid]){
            return mid;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
       
    }
    return -1;




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
    int key;
    printf("Enter the element you want to search : ");
    scanf("%d",&key);
 
    bubble(arr,size);
 
    int result= bin(arr,size,key);
     if (result == -1)
        printf("The element is not found!\n");
    else
        printf("The element is found at index %d\n", result + 1);
 
    time_t rawTime;
    struct tm *localTime;
 
    time(&rawTime);
    localTime = localtime(&rawTime);
    printf("Name : Mahammad Sami Shaik \n");
    printf("Roll No.: BT23CSE050\n");
    printf("Current local time: %s", asctime(localTime));





return 0;
}
 
