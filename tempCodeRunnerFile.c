#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

int partition(int arr[],int lo,int hi){
    int pivot=arr[hi];
    int i=lo-1;
    for(int j=lo;j<=hi;j++){
        if(arr[j]<pivot)
    {
      
      i++;
      
      int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
    }
  }
  
  int temp=arr[i+1];
      arr[i+1]=arr[hi];
      arr[hi]=temp;
  return (i+1);
    }


int quicksort(int arr[], int lo, int hi){
    
    if(lo<hi){
    int pi=partition(arr,lo,hi);
    quicksort(arr,lo,pi-1);
    quicksort(arr,pi+1,hi);

    }
    
}
int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
        printf("\n");
    }   
    int hi=size;
    int lo=0;
    quicksort(arr,lo,hi);
    for(int i = 0; i < size; i++) {
        printf("The element %d is: %d\n", i + 1, arr[i]);
    }


return 0;
}