#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
void findMin(int arr[],int size){
    int min=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]<min)
        min=arr[i];

    }
    printf("The minimum element is : %d\n",min);
}

int findMax(int arr[],int size){
    int max=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>max)
        max=arr[i];

    }
    return max;
}

void findThirdlar(int arr[],int size,int max){
    int maxs=arr[0];
     for(int i=0;i<size;i++){
        if(arr[i]>maxs && arr[i]<max)
        maxs=arr[i];

    }
    int maxt=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>maxt && arr[i]<maxs)
        maxt=arr[i];
    }
    printf("The third largest element in the given array is: %d\n ",maxt);

}

void average(int arr[], int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    float avg=sum/size;
    printf("The average of the given array is: %f\n",avg);

}

int* sortArray(int arr[], int size) {
    int* sortedArr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        sortedArr[i] = arr[i];
    }


    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sortedArr[j] > sortedArr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = sortedArr[j];
                sortedArr[j] = sortedArr[j + 1];
                sortedArr[j + 1] = temp;
            }
        }
    }
    return sortedArr;
}

int findFrequency(int arr[], int size, int target) {
    int frequency = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            frequency++;
        }
    }
    return frequency;
}

void calculateFrequencies(int arr[], int size) {
    int *frequencies = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        frequencies[i] = -1;
    }

    int ctr;

    for (int i = 0; i < size; i++) {
        ctr = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                ctr++;
                frequencies[j] = 0;
            }
        }

        if (frequencies[i] != 0) {
            frequencies[i] = ctr;
        }
    }

    for (int i = 0; i < size; i++) {
        if (frequencies[i] != 0) {
            printf("%d occurs %d times\n", arr[i], frequencies[i]);
        }
    }
    free(frequencies);
}

int findMode(int arr[], int size) {

    sortArray(arr, size);
    int mode = arr[0];
    int currentCount = 1;
    int maxCount = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mode = arr[i - 1];
            }
            currentCount = 1;
        }
    }
    if (currentCount > maxCount) {
        mode = arr[size - 1];
    }
    return mode;
}

int searchArray(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

//driver code
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int arr[size];
    for(int i=1;i<=size;i++){ 
        printf("Enter the element %d : ",i);
        scanf("%d",&arr[i-1]);
    }
    findMin(arr,size);
    int max=findMax(arr,size);
    printf("The largest element in the given array is: %d\n ",max);
    findThirdlar(arr,size,max);
    average(arr,size);
    int* sortedArr = sortArray(arr, size);
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);  // Use sortedArr, not sortedArray
    }
    printf("\n");

    // Don't forget to free the memory allocated for sortedArr
    free(sortedArr);

    printf("Mode: %d\n", findMode(arr, size));

    calculateFrequencies(arr, size);

    printf("Name: Sami\n");
    printf("BT ID.: BT23CSE050\n");

    time_t currentTime;
    time(&currentTime);

    // Convert the current time to local time
    struct tm *localTime = localtime(&currentTime);

    // Print the local time
    printf("Name: Mahammad Sami Shaik\n");
    printf("Roll No: BT23CSE050\n");
    printf("Current local time: %s", asctime(localTime));
    return 0;
}