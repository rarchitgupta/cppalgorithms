#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n) 
{  
    if (n == 1) 
        return; 
  
    int i;
    for (i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]) 
            swap(arr[i], arr[i+1]); 
  
    bubbleSort(arr, n-1); 
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

    bubbleSort(arr,n);

    cout<<"Sorted array: "<<endl;
    cout<<endl;

    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}