#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n) 
{ 
    if (n <= 1) 
        return; 
   
    insertionSort(arr, n-1); 
   
    int last = arr[n-1]; 
    int j = n-2; 
  
    while (j >= 0 && arr[j] > last) 
    { 
        arr[j+1] = arr[j]; 
        j--; 
    } 
    arr[j+1] = last; 
} 

int main()
{
    int n;
    cout<<"Enter number of array elements"<<endl;
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    int i;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    insertionSort(arr,n);

    cout<<"Sorted array: "<<endl;
    cout<<endl;

    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}