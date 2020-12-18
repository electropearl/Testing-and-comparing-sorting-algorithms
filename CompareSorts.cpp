#include <iostream>
#include <cmath>
#define MAXSIZE 5000
using namespace std;

// function protocols

void fillArray(int list[]);
void copyArray(int source[], int dest[]);
void bubbleSort(int list[]);
void selectionSort(int list[]);
void insertionSort(int list[]);

// filling the list1 array with random values

void fillArray(int list[])
{
   for(int i = 0; i < MAXSIZE; i++)
   {
       list[i] = rand() % 100;
   }
}

// To print the array

void printArray(int list[])
{
   for(int i = 0 ; i < MAXSIZE; i++)
       cout << list[i] << " ";
   cout << endl << endl;
}

// copying the array of values into another array

void copyArray(int source[], int dest[])
{
   for(int i = 0; i < MAXSIZE; i++)
   {
       dest[i] = source[i];
   }
}

// sorting the array list2 with selection sort

void selectionSort(int list[])
{
   int comparisonCount = 0;
   int assignmentCount = 0;
   int i, j, first, temp;
for ( i = MAXSIZE - 1; i > 0; i--)
{
first = 0; //initialize to subscript of first element
for(j = 1; j <= i; j++) //locate smallest element between positions 1 and i.
{
               comparisonCount++;
if( list[ j ] > list[ first ] )   
first = j;
}
temp = list[ first ]; //swap smallest found with element in position i.
list[ first ] = list[ i ];
list[ i ] = temp;
       assignmentCount++;
}
   cout << "The number of comparisons using Selection sort : " << comparisonCount << endl;
   cout << "The number of assignments using Selection sort : " << assignmentCount << endl;
   printArray(list);
}

// sorting the array list1 with bubble sort

void bubbleSort(int list[])
{
   int comparisonCount = 0;
   int assignmentCount = 0;
   int i, j, flag = 1; // set flag to 1 to start first pass
int temp; // holding variable
  
for(i = 1; (i <= MAXSIZE) && flag; i++)
{
       comparisonCount++;
flag = 0;
for (j=0; j < (MAXSIZE -1); j++)
{
if (list[j+1] < list[j]) // ascending order simply changes to <
{
temp = list[j]; // swap elements
list[j] = list[j+1];
list[j+1] = temp;
flag = 1; // indicates that a swap occurred.
                   assignmentCount++;
}
}
}
   cout << "The number of comparisons using Bubble sort : " << comparisonCount << endl;
   cout << "The number of assignments using Bubble sort : " << assignmentCount << endl;
   printArray(list);
}

// sorting the array list3 with insertion sort

void insertionSort(int list[])
{
   int i, j, key;
   int comparisonCount = 0;
   int assignmentCount = 0;
for(j = 1; j < MAXSIZE; j++) // Start with 1 (not 0)
{
key = list[j];
for(i = j - 1; (i >= 0) ; i--) // Smaller values move up
{
           comparisonCount++;
           if(list[i] > key)
           {
               assignmentCount++;
list[i+1] = list[i];
           }
           else
               break;
}
list[i+1] = key; //Put key into its proper location
       assignmentCount++;
}
   cout << "The number of comparisons using Insertion sort : " << comparisonCount << endl;
   cout << "The number of assignments using Insertion sort : " << assignmentCount << endl;
   printArray(list);
}

int main() {

   int list1[MAXSIZE];
   int list2[MAXSIZE];
   int list3[MAXSIZE];

   fillArray(list1);
   copyArray(list1, list2);
   copyArray(list1, list3);

   bubbleSort(list1);
   selectionSort(list2);
   insertionSort(list3);

   return 0;
}