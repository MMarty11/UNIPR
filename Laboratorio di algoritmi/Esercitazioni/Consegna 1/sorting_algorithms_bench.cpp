#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

/// intero massimo usato
#define MAX_COUNT 1000000

// compilazione: g++ -xc++ consegna1-loader.c
//

// Il programma carica il file data.txt contenente 107 righe con i dati di contagi covid per provincia
// ./a.out
// In output viene mostrato il numero di accessi in read alla memoria per eseguire il sorting di ciascuna riga

// OBIETTIVO:
// Creare un algoritmo di sorting che minimizzi la somma del numero di accessi per ogni sorting di ciascuna riga del file


/// contatori
int ct_swap = 0;
int ct_cmp = 0;
int ct_read = 0;


/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

void make_file(int *A, int dim, int test)
{
  string filename = "array_sorted_" + to_string(test) + ".txt"; 
  ofstream myfile(filename);
  if (myfile.is_open())
  {
    for(int i = 0; i < dim-1; i++){
        myfile << A[i] << ", " ;
    }
    myfile << A[dim-1];
    myfile.close();
  }
  else cout << "Unable to open file";
}


void fill_array(int *A, int size, int type)
{
    int _min = -20;
    int _max = size+_min;
    
    switch (type)
    {
        
        case 1:  //crescente
            for(int i=0; i<size; i++)
                A[i] = i+_min;
            break;
        case 2:  //decrescente
            for(int i=0; i<size; i++)
                A[i] = _max-i;
            break;
        case 3:  //quasi crescente
            for(int i=0; i<size; i++)
                A[i] = i+_min;
            A[3]=8; A[97]=100; A[98]=99; A[6]=9; A[45]=44; A[11]=-3; A[12]=0;
            break;
        case 4:  //quasi decrescente
            for(int i=0; i<size; i++)
                A[i] = _max-i;
            A[3]=88; A[97]=66; A[33]=-3; A[6]=87; A[45]=44; A[11]=99; A[12]=100;
            break;
        case 5:  //random
            for(int i=0; i<size; i++)
                A[i] =  _min + rand() % (( _max + 1 ) - _min);;
            break;
    }
    
}

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
  /// aggiorno contatore globale di swap
  ct_swap++;
}



//// ---- ALGORITMI DI SORTING ---- ////

/// QUICK SORT
int partition(int *A, int start, int end)
{

  /// copia valori delle due meta p..q e q+1..r
  int i = start - 1;

  for (int j = start; j < end; j++)
  {
    ct_cmp++;
    ct_read++;
    ct_read++;
    if (A[j] <= A[end])
    {
      i++;
      ct_read++;
      ct_read++;
      swap(A[i], A[j]);
    }
  }
  ct_read++; ct_read++;
  swap(A[i + 1], A[end]);

  return i + 1;
}

int partition_2(int arr[], int start, int end)
{
    ct_read++;
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        ct_read++;
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    ct_read++; ct_read++;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
        ct_read++;
        while (arr[i] <= pivot) {
            i++;
        }
        ct_read++;
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            ct_read++; ct_read++;
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 

void quick_sort(int *A, int start, int end)
{
  if (start < end)
  {
    // partitioning the array
    int p = partition_2(A, start, end);

    printArray(A,10);


    // Sorting the left part
    quick_sort(A, start, p - 1);

    // Sorting the right part
    quick_sort(A, p + 1, end);
  }
}



/// QUICK SORT 3 WAY
void TWP(int A[], int m, int n, int &begin, int &end)
{
  ct_read++;
  int pivot = A[m];
  begin = m, end = n;
  int x;

  for (int i = begin + 1; i <= end; i++)
  {
    ct_read++;
    x = A[i];
    if (x < pivot)
    {
      ct_read++;
      ct_read++;
      swap(A[i], A[begin]);
      begin++;
    }
    else if (x > pivot)
    {
      ct_read++;
      ct_read++;
      swap(A[i], A[end]);
      end--;
      i--;
    }
  }
}

void quicksort_3_way(int A[], int m, int n)
{
  if (m >= n)
  {
    return;
  }
  int begin, end;
  TWP(A, m, n, begin, end);
  quicksort_3_way(A, m, --begin);
  quicksort_3_way(A, ++end, n);
}



/// MERGE SORT
void merge_prof(int *A, int p, int q, int r, int *L, int *R)
{

  /// copia valori delle due meta p..q e q+1..r
  int i = 0;
  int j = 0;
  int k = 0;

  for (i = 0; i < q - p + 1; i++)
  {
    L[i] = A[p + i];
    ct_read++;
  }
  L[i] = 1000000; /// un numero grande

  for (i = 0; i < r - q; i++)
  {
    R[i] = A[q + 1 + i];
    ct_read++;
  }
  R[i] = 1000000; /// un numero grande

  i = 0; /// usato per gestire array L
  j = 0; /// usato per gestire array R

  int left, right;
  for (k = p; k <= r; k++)
  {
    ct_read++; ct_read++;
    left = L[i];
    right = R[j];
    if (left <= right)
    {
      A[k] = left;
      i++;
    }
    else
    {
      A[k] = right;
      j++;
    }
  }
}

void merge_sort_prof(int *A, int p, int r, int *L, int *R)
{
  /// gli array L e R sono utilizzati come appoggio per copiare i valori: evita le allocazioni nella fase di merge
  if (p < r)
  {
    int q = (p + r) / 2;

    merge_sort_prof(A, p, q, L, R);
    merge_sort_prof(A, q + 1, r, L, R);

    merge_prof(A, p, q, r, L, R);
  }
}

void merge(int *A, int left, int middle, int right)
{
  int n = middle - left + 1; // size of first array
  int m = right - middle;    // size of rest of the elements
  int first[n];
  for (int i = 0; i < n; i++)
  {
    ct_read++;
    first[i] = A[left + i];
    // cout<<first[i]<<" ";
  }
  // cout<<endl;
  int rest[m];
  for (int i = 0; i < m; i++)
  {
    ct_read++;
    rest[i] = A[middle + 1 + i];
    // cout<<rest[i]<<" ";
  }
  // cout<<endl;
  int ptr1 = 0;
  int ptr2 = 0;
  int index = left;
  int _first, _rest;
  // MERGE PROCESS WITH COMPARISONS
  while (ptr1 < n && ptr2 < m)
  {
    ct_read++;
    ct_read++;
    _first = first[ptr1];
    _rest = rest[ptr2];
    if (_first < _rest)
    {
      A[index] = _first;
      index++;
      ptr1++;
    }
    else
    {
      A[index] = _rest;
      index++;
      ptr2++;
    }
  }
  while (ptr1 < n)
  {
    ct_read++;
    A[index] = first[ptr1];
    index++;
    ptr1++;
  }
  while (ptr2 < m)
  {
    ct_read++;
    A[index] = rest[ptr2];
    index++;
    ptr2++;
  }
}

void merge_sort(int *A, int left, int right)
{
  if (left < right)
  {
    // LETS DIVIDE
    int middle = (left + right) / 2;
    merge_sort(A, left, middle);
    merge_sort(A, middle + 1, right);
    // after dividing lets merge it
    merge(A, left, middle, right);
  }
}



/// SELECTION SORT
void selectionSort(int A[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++){
          ct_read++;
          ct_read++;
          if (A[j] < A[min_idx]) 
            min_idx = j; 
        }
  
        // Swap the found minimum element with the first element 
        swap(A[min_idx], A[i]);
        ct_read++;
        ct_read++;
    } 
} 
  


/// INSERTION SORT
void insertion_sort(int *A, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = i - 1; j >= 0; j--)
    {
      ct_read++; ct_read++;
      ct_read++; ct_read++;
      if (A[j] > A[j + 1])
      {
        swap(A[j], A[j + 1]);
      }
      else
      {
        //// cosa succede se si rimuove questo break?
        break;
      }
    }
  }
}



/// COUNTING SORT
void counting_sort(int *A_input, int *B_output, int *C_counter, int n, int k)
{
  /// A: array in input 0..n-1
  /// B: array in output 0..n-1
  /// C: array per conteggi 0..k
  /// n: elementi da ordinare
  /// k: valore massimo contenuto in A

  /// reset array conteggi
  for (int i = 0; i <= k; i++)
  { 
    C_counter[i] = 0;
  }

  /// conteggio istogramma
  int _ct_value;
  for (int j = 0; j < n; j++)
  { 
    ct_read++;
    _ct_value = A_input[j];
    if(_ct_value >= 0){
      C_counter[_ct_value]++;
    }
  } 
  
  /// C_counter[i] contiene il numero di elementi <= i
  for (int i = 1; i <= k; i++)
  {
    ct_read++;
    C_counter[i] += C_counter[i - 1];
  }

  /// per ogni elemento originale in A ->
  /// mi chiedo nel conteggio C quanti sono gli elementi minori o uguali:
  /// questo corrisponde alla posizione dell'elemento in B
  int _value, _pos;
  for (int j = n - 1; j >= 0; j--)
  {
    ct_read++;
    _value = A_input[j];
    if(_ct_value >= 0)  //escludo i valori negativi
    {
      ct_read++;
      _pos = C_counter[_value];
      B_output[_pos - 1] = _value;  // inserisco il dato nella sua posizione corretta
      C_counter[_value] = _pos - 1; 
    }
  }

   // Copy the sorted elements into original array
  for (int i = 0; i < n; i++) {
    ct_read++;
    A_input[i] = B_output[i];
  }
}

void counting_sort_negativi(int *A_input, int *B_output, int *C_counter, int n, int k_max, int k_min)
{
  /// A: array in input 0..n-1
  /// B: array in output 0..n-1
  /// C: array per conteggi 0..k
  /// n: elementi da ordinare
  /// k: valore massimo contenuto in A

  /// reset array conteggi
  for (int i = 0; i <= (k_max+k_min); i++)
  { 
    C_counter[i] = 0;
  }

  /// conteggio istogramma
  for (int j = 0; j < n; j++)
  { 
      C_counter[A_input[j]+k_min]++;
      ct_read++;
  } 
  
  /// C_counter[i] contiene il numero di elementi <= i
  for (int i = 1; i <= (k_max+k_min); i++)
  {
    C_counter[i] += C_counter[i - 1];
    ct_read++;
  }

  /// per ogni elemento originale in A ->
  /// mi chiedo nel conteggio C quanti sono gli elementi minori o uguali:
  /// questo corrisponde alla posizione dell'elemento in B
  int _value, _pos;
  for (int j = n - 1; j >= 0; j--)
  {
    ct_read++; ct_read++;
    _value = A_input[j];
    _pos = C_counter[_value+k_min];
    B_output[_pos - 1] = _value;  // inserisco il dato nella sua posizione corretta
    C_counter[_value+k_min] = _pos - 1;  
  }

   // Copy the sorted elements into original array
  for (int i = 0; i < n; i++) {
    ct_read++;
    A_input[i] = B_output[i];
  }
}



/// BUBBLE SORT
void bubbleSort(int A[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            ct_read++;
            ct_read++;
            if ( A[j] > A[j + 1] )
            {
                ct_read++;
                ct_read++;
                swap( A[j], A[j + 1] );
            }
        }
    }
}



/// RADIX SORT
int getMax(int A[], int n) {
  ct_read++;
  int max = A[0];
  int _value;
  for (int i = 1; i < n; i++){
    ct_read++;
    _value = A[i];
    if (_value > max)
      max = _value;
  }
  return max;
}
void countingSort(int A[], int size, int place) {
  // Using counting sort to sort the elements in the basis of significant places
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  int _value;
  for (int i = 0; i < size; i++){
    ct_read++;
    ct_read++;
    _value = A[i];
    count[(_value / place) % 10] = count[(_value / place) % 10] + 1;
  }

  // Calculate cumulative count
  for (int i = 1; i < max; i++){
    ct_read++;
    count[i] += count[i - 1];
  }

  // Place the elements in sorted order
  int _pos;
  for (int i = size - 1; i >= 0; i--) {
    ct_read++; ct_read++;
    _value = A[i];
    _pos = count[(_value / place) % 10];
    output[_pos - 1] = _value;
    count[(_value / place) % 10] = _pos - 1;
  }

  // Replace A elements with output elements that are oredered (? ct_read++;)
  for (int i = 0; i < size; i++){
    ct_read++;
    A[i] = output[i];
  }
}
void radixsort(int A[], int *B_output, int *C_counter, int n, int k_max, int k_min) {
  // Get maximum element
  int max = getMax(A, n);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    //countingSort(A, n, place);
    counting_sort_negativi(A,B_output,C_counter,n,k_max,abs(k_min));
}



/// HEAP SORT
void heapify(int A[], int n, int i)
{
   // To heapify a subtree rooted with node i
  // which is an index in arr[].
  // n is size of heap

  // Initialize largest as root
    int largest = i;
   
  // left = 2*i + 1
    int l = 2 * i + 1;
   
  // right = 2*i + 2
    int r = 2 * i + 2;
 
    ct_read++; ct_read++;
    // If left child is larger than root
    if (l < n && A[l] > A[largest])
        largest = l;
 
    ct_read++; ct_read++;
    // If right child is larger than largest
    // so far
    if (r < n && A[r] > A[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        ct_read++;
        ct_read++;
        swap(A[i], A[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(A, n, largest);
    }
}
// Main function to do heap sort
void heapSort(int A[], int n)
{
   
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
 
    // One by one extract an element
    // from heap
    for (int i = n - 1; i > 0; i--) {
       
        ct_read++;
        ct_read++;
        // Move current root to end
        swap(A[0], A[i]);
 
        // call max heapify on the reduced heap
        heapify(A, i, 0);
    }
}



/// PIGEONHOLE SORT
/* Sorts the array using pigeonhole algorithm */
void pigeonholeSort(int A[], int start, int end, int _max, int _min)
{
    /* ct_read++; ct_read++;
    // Find minimum and maximum values in arr[]
    int min = A[start], max = A[start];
    int _value;
    for (int i = start+1; i < end; i++)
    {
        ct_read++;
        _value = A[i];
        if (_value < min)
            min = _value;
        if (_value > max)
            max = _value;
    } */

    int _value;
    int range = _max - _min + 1; // Find range
 
    // Create an array of vectors. Size of array
    // range. Each vector represents a hole that
    // is going to contain matching elements.
    vector<int> holes[range];
 
    // Traverse through input array and put every
    // element in its respective hole
    for (int i = start; i < end; i++){
        ct_read++;
        _value = A[i];
        holes[_value-_min].push_back(_value);
    }
 
    // Traverse through all holes one by one. For
    // every hole, take its elements and put in
    // array.
    int index = start;  // index in sorted array
    for (int i = 0; i < range; i++)
    {
       vector<int>::iterator it;
       ct_read++; // riferito a "holes[i].begin()""
       ct_read++; // riferito a "holes[i].end()"
       for (it = holes[i].begin(); it != holes[i].end(); ++it){
            ct_read++; // riferito a "holes[i].end()"
            A[index++]  = *it;
       }
    }
}



/// BUCKET SORT
void bucketSort_0(int A[], int n)
{
    // 1) Create n empty buckets
    vector<int> B[n];
    //int _value;
 
    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {
        ct_read++;
        //_value = A[i];
        int bi = n *  A[i]; // Index in bucket
        B[bi].push_back( A[i]);
    }
 
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++){
        ct_read++; ct_read++;
        sort(B[i].begin(), B[i].end());  //PROBLEMA!!! Qui non vengono contate le letture! SOL: usa uno degli algoritmi scritti su
    }
 
    // 4) Concatenate all buckets into A[]
    int index = 0;
    for (int i = 0; i < n; i++){
        ct_read++;  
        for (int j = 0; j < B[i].size(); j++){
            ct_read++;
            A[index++] = B[i][j];
        }
    }
}
void bucketSort(int arr[],int *bucket[],int n,int _max)
{
    static int i,j[10],k,l,d=1;
    int c = _max;
  
    for(int m=0;m<c;m++)
    {
        for(i=0;i<10;i++)
            j[i]=0;
        for(i=0;i<n;i++)
        {
            ct_read++; ct_read++;
            k=(arr[i]/d)%10;
            bucket[k][j[k]]=arr[i];
            j[k]++;
        }
     
        l=0;
        for(i=0;i<10;i++)
        {
            ct_read++;
            for(k=0;k<j[i];k++)
            {
                ct_read++;
                arr[l]=bucket[i][k];
                l++;
            }
        }
        d*=10;
    }
}


/// TIM SORT

// This function sorts array from left index to
// to right index which is of size atmost RUN
void insertionSort_tim(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        ct_read++;
        int temp = arr[i];
        int j = i - 1;
        ct_read++; //riferito a "arr[j]"
        int _value = arr[j];
        while (j >= left && _value > temp)
        {
            arr[j+1] = _value;
            j--;
            ct_read++;
            _value = arr[j];
        }
        arr[j+1] = temp;
    }
}
 
// Merge function merges the sorted runs
void merge_tim(int arr[], int l, int m, int r)
{
     
    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++){
        ct_read++;
        left[i] = arr[l + i];
    }
    for (int i = 0; i < len2; i++){
        ct_read++;
        right[i] = arr[m + 1 + i];
    }
 
    int i = 0;
    int j = 0;
    int k = l;
 
    // After comparing, we
    // merge those two array
    // in larger sub array
    int _left, _right;
    while (i < len1 && j < len2)
    {
        ct_read++; ct_read++;
        _left = left[i];
        _right = right[j];
        if (_left <= _right)
        {
            arr[k] = _left;
            i++;
        }
        else
        {
            arr[k] = _right;
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        ct_read++;
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        ct_read++;
        arr[k] = right[j];
        k++;
        j++;
    }
}
 
// Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(int arr[], int n, int RUN)
{
     
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSort_tim(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n;
                             size = 2*size)
    {
         
        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (int left = 0; left < n;
                             left += 2*size)
        {
             
            // find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
 
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
              if(mid < right)
                merge_tim(arr, left, mid, right);
        }
    }
}



/// SHELL SORT
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            ct_read++;
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                ct_read++; ct_read++;
                arr[j] = arr[j - gap];
            }
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}




// Partitions arr[0..n-1] around [lowVal..highVal]
void threeWayPartition(int arr[], int n,
                int lowVal, int highVal, int &start, int &end)
{
    // Initialize ext available positions for
    // smaller (than range) and greater elements
    start = 0;
    end = n-1;
 
    // Traverse elements from left
    for (int i=0; i<=end;)
    {
        // If current element is smaller than
        // range, put it on next available smaller
        // position.
        if (arr[i] < lowVal)
        {
          //if i and start are same in that case we can't swap
          //swap only if i is greater than start
          if(i==start)
          {
            start++;
            i++;
          }
          else
            swap(arr[i++], arr[start++]);
        }
 
        // If current element is greater than
        // range, put it on next available greater
        // position.
        else if (arr[i] > highVal)
            swap(arr[i], arr[end--]);
 
        else
            i++;
    }

    printf("start: %d -- end: %d", start, end);
}
 

void A_counting_sort_negativi(int *A_input, int *B_output, int *C_counter, int start, int end, int k_max, int k_min)
{
  /// A: array in input 0..n-1
  /// B: array in output 0..n-1
  /// C: array per conteggi 0..k
  /// n: elementi da ordinare
  /// k: valore massimo contenuto in A

  /// reset array conteggi
  for (int i = 0; i <= (k_max+k_min); i++)
  { 
    C_counter[i] = 0;
  }

  /// conteggio istogramma
  for (int j = start; j < end; j++)
  { 
      C_counter[A_input[j]+k_min]++;
      ct_read++;
  } 
  
  /// C_counter[i] contiene il numero di elementi <= i
  for (int i = 1; i <= (k_max+k_min); i++)
  {
    C_counter[i] += C_counter[i - 1];
    ct_read++;
  }

  /// per ogni elemento originale in A ->
  /// mi chiedo nel conteggio C quanti sono gli elementi minori o uguali:
  /// questo corrisponde alla posizione dell'elemento in B
  int _value, _pos;
  for (int j = end - 1; j >= start; j--)
  {
    ct_read++; ct_read++;
    _value = A_input[j];
    _pos = C_counter[_value+k_min];
    B_output[_pos - 1] = _value;  // inserisco il dato nella sua posizione corretta
    C_counter[_value+k_min] = _pos - 1;  
  }

   // Copy the sorted elements into original array
  for (int i = start; i < end; i++) {
    ct_read++;
    A_input[i] = B_output[i];
  }
}





// Sort the given array
void sort(int *A, int n, int _max, int _min, int *B_output, int *C_counter, int *L, int *R)
{
    // int *bucket[10];
    // for(int i=0; i<10; i++)
    //     bucket[i]=new int[n-1];

    // bubbleSort(A, n);   // 667216,720880.7,780950
    // selectionSort(A,n);  // 551304,551304.0,551304
    // insertion_sort(A, n);  // 233158,340372.1,460496
    // quick_sort(A,0,n);  // 22059,43085.5,150308
    // heapSort(A,n);  // 29624,37896.5,40628
    // radixsort(A,B_output,C_counter,n,_max,_min);  //18295,36494.5,120808
    // quicksort_3_way(A, 0, n);  // 12076,24545.4,39876
    // merge_sort_prof(A, 0, n - 1, L, R);  // ???
    // merge_sort(A,0,n); // 24772,25346.7,25980 ???
    // counting_sort(A,B_output,C_counter,n,_max);  // 5827,8583.0,23991 *(!) SOLO VALORI POSITIVI 
    // counting_sort_negativi(A,B_output,C_counter,n,_max,abs(_min));  // 5844,8893.9,24736 *(!) VALORI POSITIVI E NEGATIVI 
    // pigeonholeSort(A,n);  // 4380,7432.0,23267
    // bucketSort(A,bucket,n,_max);  //23102,24649.2,25874
    // timSort(A,n,32);
    // shellSort(A,n);


    //pigeonholeSort(A, 0, n, _max, _min);


    int lowVal=0, highVal=_max/3; //valori da cui partizionare (es: 0 e 300)
    int index_start = 0, index_end = 0; //indici dei valori partizionati (es: [0..start]=negativi, [start..end]=positivi_fino_300, [end..n]=positivi_da_300)
    
    threeWayPartition(A, n, lowVal, highVal, index_start, index_end);
    // stampa l'array partizionato
      printf("\nArray partizionato: \n");
      printArray(A,n);

    //ordina la partizione 1 dei numeri negativi, ovvero fino a lowVal
    pigeonholeSort(A, 0, index_start, 0, _min);
    //ordina la partizione che va da lowVal a highVal 
    quick_sort(A, index_start, index_end);
    //ordina la partizione che va da highVal a _max 
    pigeonholeSort(A, index_end, n, _max, highVal);


}

void find_min_max(int A[], int n, int &max, int &min)
{
    max = 0; min = 0;
    int x;
    
    for(int i=0; i<n; i++)
    {
        //ct_read++;
        x = A[i];
        if (max < x)
            max = x;
        if (min > x)
            min = x;
    }
}


int main(int argc, char **argv)
{
    /// type: 1-crescente, 2-decrescente, 3-quasiCrescente, 4-quasiDescrescente, 5-random
    int array_type = 5;
    /// dimensione dell'array
    int size = 100; 


    int *A;
    int *B_output; /// usato come array di output (counting sort)
    int *C_counter; /// usato come array per i conteggi (counting sort)
    int *L; /// usato come buffer di appoggio (merge sort)
    int *R; /// usato come buffer di appoggio  (merge sort)
    int _max = 0; /// valore massimo nell'array di input (counting sort)
    int _min = 0; /// valore massimo nell'array di input (counting sort)

    /// numero di letture in RAM
    int read_min;
    int read_max;
    long read_avg;

    for(int i=3; i<4; i++)
    {
        size = pow(10,i);

        /// allocazione array
        A = new int[size];
        B_output = new int[size];
        C_counter = new int[MAX_COUNT];
        L = new int[size + 1];
        R = new int[size + 1];

        read_min = -1;
        read_max = -1;
        read_avg = 0;

        /// inizializzazione array
        for (int i = 0; i < size; i++)
        {
            //inizializzazione array
            B_output[i] = -1;
        }

        ct_swap = 0;
        ct_cmp = 0;
        ct_read = 0;

        /// riempe l'array con dei valori
        fill_array(A,size,array_type);

        /// trova il massimo e il minimo
        find_min_max(A, size, _max, _min);

        // stampa l'array disordinato
        // printf("Array: \n");
        // printArray(A,size);

        /// ordino l'array
        sort(A,size,_max,_min, B_output, C_counter, L, R);


        // stampa l'array ordinato
        //printf("Array ordinato: \n");
        //printArray(A,size);


        /// stampa statistiche
        read_avg += ct_read;
        if (read_min < 0 || read_min > ct_read)
        read_min = ct_read;
        if (read_max < 0 || read_max < ct_read)
        read_max = ct_read;
        
        printf("Array size: %d \nRAM reads: %d,%.1f,%d\n\n", size,
                read_min, (0.0 + read_avg), read_max);
    }

    /// dealloco l'array di supporto per i conteggi (dipende da k = massimo nell'array in uso)
    delete [] A;
    delete [] B_output;
    delete [] C_counter;
    delete [] L;
    delete [] R;


    return 0;
}
