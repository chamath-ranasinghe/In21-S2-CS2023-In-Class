#include <iostream>
using namespace std;

// function to swap to elements in an array
void swap(int arr[], int indexone, int indextwo){
   int temp = arr[indexone];
   arr[indexone] = arr[indextwo];
   arr[indextwo] = temp; 
}

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int l = 2*root+1; // Get left child index
   int r = 2*root+2; // Get right child index

   int largest = root;
   if (l <= n && arr[l] > arr[root] ){ //If value of left child greater than of root, assign it as largest
         largest = l;
   } else{
         largest = root;
   }    

   if (r <= n && arr[r] > arr[largest]){
         largest = r;
   }

   if (largest != root){ // If either left or right child is larger swap them with root, recall heapify
         swap(arr,root,largest);
         heapify(arr,n,largest);
   }
  
   
}

// Function to build a max heap
void buildMaxHeap(int arr[],int n){
   int heapsize = n;
   for(int i=heapsize/2 -1;i>=0;i--){
      heapify(arr,heapsize,i);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   buildMaxHeap(arr,n);

   // extracting elements from heap one by one
   for(int i = n-1; i>0; i--){
      swap(arr,i,0);   
      heapify(arr,i-1,0);

   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; i++)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   const int MAX_SIZE = 100;
   int n;
   cout<<"Enter the size of your array: ";
   cin>>n;

   int heap_arr[MAX_SIZE]; // Create an array with a maximum size

   for (int i=0;i<n;i++){ // Take array elements as input from user
      cout<<"Element "<<i<<":";
      cin>>heap_arr[i];
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}