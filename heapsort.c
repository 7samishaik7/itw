#include <stdio.h>
 
 
 
int heap[100], n = 0;
 
 
 
void insertElement(int priority)
 
{
 
n++;
 
heap[n] = priority; int i = n;
 
 
while (i > 1 && heap[i] > heap[i / 2])
 
{
 
int temp = heap[i]; heap[i] = heap[i / 2]; heap[i / 2] = temp;
i = i / 2;
 
}
 
}
 
 
 
int deleteMax()
 
{
 
if (n == 0)
 
{
 
printf("No tasks left in the queue!\n");

return -1;
 
}
 
 
 
int maxPriority = heap[1]; heap[1] = heap[n];
n--;
 
int i = 1;
 
 
 
while (2 * i <= n)
 
{
 
int j = 2 * i;
 
if (j + 1 <= n && heap[j + 1] > heap[j]) j++;
if (heap[i] < heap[j])
 
{
 
int temp = heap[i]; heap[i] = heap[j]; heap[j] = temp;
i = j;
 
}
 
else
 
break;
 
}

return maxPriority;
 
}
 
 
 
void printHeapAsTree()
 
{
 
printf("Heap structure (tree representation):\n"); int level = 1;
int count = 0;
 
 
 
for (int i = 1; i <= n; i++)
 
{
 
printf("%d ", heap[i]);
 
 
 
count++;
 
 
 
if (count == level)
 
{
 
printf("\n"); level *= 2;
count = 0;
 
}
 
}
 
printf("\n");
 
}

int main()
 
{
 
 
 
insertElement(5); insertElement(3); insertElement(8); insertElement(1); insertElement(2); insertElement(7); insertElement(4); insertElement(6);
 
 
printHeapAsTree();
 
 
 
printf("Processing tasks in order of priority:\n"); while (n > 0)
{
 
int task = deleteMax(); if (task != -1)
printf("Task with priority %d processed.\n", task);
 
}
 
 
 
return 0;

}
