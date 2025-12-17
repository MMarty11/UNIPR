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

int ct_swap = 0;
int ct_cmp = 0;
int ct_read = 0;

int max_dim = 0;
int ntests = 107;
int ndiv = 1;
int details = 0;
int graph = 0;

int n = 0; /// dimensione dell'array

/* Parse command line arguments */
int parse_cmd(int argc, char **argv)
{
  /// parsing argomento
  max_dim = 743;

  for (int i = 1; i < argc; i++)
  {
    if (argv[i][1] == 'd')
      ndiv = atoi(argv[i] + 3);
    if (argv[i][1] == 't')
      ntests = atoi(argv[i] + 3);
    if (argv[i][1] == 'v')
      details = 1;
    if (argv[i][1] == 'g')
    {
      graph = 1;
      ndiv = 1;
      ntests = 1;
    }
  }

  return 0;
}

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

/* Function to swap two elements */
void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
  /// aggiorno contatore globale di swap
  ct_swap++;
}

/* Find min and max in the array */
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



/*********************************************************************************************************/
//// ---- PARTIZIONAMENTO ---- ////

/* Partitions arr[0..n-1] around [lowVal..highVal] */
void threeWayPartition(int arr[], int n,
                int lowVal, int highVal, int &start, int &end)
{
    // Initialize ext available positions for
    // smaller (than range) and greater elements
    start = 0;
    end = n-1;
    int _value;
    // Traverse elements from left
    for (int i=0; i<=end;)
    {
        // If current element is smaller than
        // range, put it on next available smaller
        // position.
        ct_read++;
        _value = arr[i];
        if (_value < lowVal)
        {
          //if i and start are same in that case we can't swap
          //swap only if i is greater than start
          if(i==start)
          {
            start++;
            i++;
          }
          else{
            ct_read++;
            ct_read++;
            swap(arr[i++], arr[start++]);
          }
        }
 
        // If current element is greater than
        // range, put it on next available greater
        // position.
        else if (_value > highVal){
            ct_read++;
            ct_read++;
            swap(arr[i], arr[end--]);
        }
 
        else
            i++;
    }

    //printf("start: %d -- end: %d", start, end);
}



/*********************************************************************************************************/
//// ---- ALGORITMI DI SORTING ---- ////

/// SHELL SORT
int shellSort(int arr[], int start, int end)
{
    // Start with a big gap, then reduce the gap
    for (int gap = (start+end)/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < end; i += 1)
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


/// QUICK SORT
int partition(int *A, int p, int r)
{

  /// copia valori delle due meta p..q e q+1..r
  int i = p - 1;

  for (int j = p; j < r; j++)
  {
    ct_cmp++;
    ct_read++;
    ct_read++;
    if (A[j] <= A[r])
    {
      i++;
      ct_read++;
      ct_read++;
      swap(A[i], A[j]);
    }
  }
  ct_read++; ct_read++;
  swap(A[i + 1], A[r]);

  return i + 1;
}

void quick_sort(int *A, int p, int r)
{
  /// gli array L e R sono utilizzati come appoggio per copiare i valori: evita le allocazioni nella fase di merge
  if (p < r)
  {
    int q = partition(A, p, r);
    quick_sort(A, p, q - 1);
    quick_sort(A, q + 1, r);
  }
}



/*********************************************************************************************************/
/* Sort the given array */
void sort(int *A, int n)
{
    int lowVal=0, highVal=595; //valori da cui partizionare (es: 0 e 300)
    int index_start = 0, index_end = 0; //indici dei valori partizionati (es: [0..start]=negativi, [start..end]=positivi_fino_300, [end..n]=positivi_da_300)
    
    /// partiziona l'array
    threeWayPartition(A, n, lowVal, highVal, index_start, index_end);

    /// ordina la partizione 1 dei numeri negativi, ovvero fino a lowVal
    if(index_start>0)
      shellSort(A, 0, index_start);

    /// ordina la partizione che va da lowVal a highVal 
    pigeonholeSort(A, index_start, index_end, highVal, 0);

    /// ordina la partizione che va da highVal a _max 
    quick_sort(A, index_end, n);

    /// TOTALE: RAM reads: 3437,4456.1,13066 (in media 6 letture per elemento)
}



/*********************************************************************************************************/
/* Main function */
int main(int argc, char **argv)
{
  int i, test;
  int *A;
  int _max; /// valore massimo nell'array di input
  int _min; /// valore massimo nell'array di input

  if (parse_cmd(argc, argv))
    return 1;

  /// allocazione array
  A = new int[max_dim];

  n = max_dim;

  ifstream input_data;
  input_data.open("data.txt");

  int read_min = -1;
  int read_max = -1;
  long read_avg = 0;

  //// lancio ntests volte, 107 array di 743 elementi (dati di 107 province in 743 giorni di Covid)
  for (test = 0; test < ntests; test++)
  {
    _max = 0;
    _min = 0;

    /// inizializzazione array: numeri letti dal file data.txt
    for (i = 0; i < n; i++)
    {
      char comma;
      input_data >> A[i];
      input_data >> comma;
    
      // trovo il valore massimo contenuto in A (+eff rispetto a "find_min_max()")
      /*if (k_max < A[i])
        k_max = A[i];

      if (k_min > A[i])
        k_min = A[i];*/
    }

    if (details)
    {
      printf("caricato array di dimensione %d\n", n);
      printArray(A, n);
    }

    /// azzero i contatori
    ct_swap = 0;
    ct_cmp = 0;
    ct_read = 0;

    /// trova il valore minimo e il valore massimo
    //find_min_max(A,n,_max,_min);

    //// ALGORITMO DI SORTING
    sort(A,n);

    if (details)
    {
      printf("Output:\n");
      printArray(A, n);
    }

    /// statistiche
    read_avg += ct_read;
    if (read_min < 0 || read_min > ct_read)
      read_min = ct_read;
    if (read_max < 0 || read_max < ct_read)
      read_max = ct_read;
     printf("Test %d %d\n", test, ct_read);  // elenca le letture(min,avg,max) dei 107 test svolti 
    
  }

  printf("RAM reads: %d,%.1f,%d\n",
         read_min, (0.0 + read_avg) / ntests, read_max);

  delete [] A;  /// dealloco l'array


  return 0;
}
