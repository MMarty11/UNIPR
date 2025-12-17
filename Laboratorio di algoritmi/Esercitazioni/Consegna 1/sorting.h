#ifndef SORTING_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define SORTING_H

#include <bits/stdc++.h>

void selectionSort(int* , int);
void bubbleSort(int arr[], int n);
void mergeSort(int array[], int const begin, int const end);
void quickSort(int arr[], int low, int high);
void quicksort3way(int a[], int l, int r);
void heapSort(int arr[], int n);
void countSort(char arr[]);
void radixsort(int arr[], int n);

#endif
