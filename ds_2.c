#include<stdio.h>
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
    printarr(arr, size);
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

    
    
    // insert(arr, &size);

    // delete(arr, &size);

    int i=linearsearch(arr, &size);
    if(i==-1)
    printf("The element is not found !!");
    else
    printf("The element is found at index %d",i+1);

    

    return 0;
}
