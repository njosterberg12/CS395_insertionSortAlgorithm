/***************************************************************************************************************
 * Id: oste1799
 * Purpose:
 *  This program implements the insertion sort algorithm
 * Input:
 *  ./assignment11 # # # ... where # are the integers of the array. Ex. ./assignment11 3 5 2
 * Output:
 *  array A[0..n-1) sorted in nondecreasing order
 * Compile:
 *  ex. gcc -Wall -o assignment11 assignment11.c
 ***************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *arr, int vals);
void printArray(int *arr,  int vals, int sortCount);
int main(int argc, char *argv[]){
   int size = argc - 1;
   int i;
   if(argc < 2)
   {
      printf("Not enough values to sort. Please enter more values.");
      return 0;
   }
   int *arr = malloc(sizeof(int)*size); // dynamic memory allocation for integer array of size argc-1
   for(i = 0; i < size; i++)
   {
      arr[i] = atoi(argv[i+1]);
   }
   insertionSort(arr, size);
   return 0;
}
// This function implements an insertion sort of a dynamically allocated array
void insertionSort(int *arr, int vals){
   int i;
   int v;
   int j;
   int sortCount = 0;
   for(i = 0; i < vals; i++)
   {
      v = arr[i];
      j = i - 1;
      while(j >= 0 && arr[j] > v)
      {
         arr[j+1] = arr[j];
         j = j-1;
      }
      arr[j+1] = v;
      sortCount++;
      printArray(arr, vals, sortCount);
   }
}
// This function prints the array
void printArray(int *arr, int vals, int sortCount)
{
   int i = 0;
   for(i = 0; i < sortCount; i++)
   {
      printf("%i ", arr[i]);
   }
   printf("| ");
   for(i = sortCount; i < vals; i++)
   {
      printf("%i ", arr[i]);
   }
   printf("\n");
}