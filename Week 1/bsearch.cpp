#include <iostream>
#include <stdio.h> 

using namespace std;

int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
         
        if (arr[mid] == x)  
		return mid; 
  
         
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x); 
  
        return binarySearch(arr, mid+1, r, x); 
   } 
   
   return -1; 
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

    int x;
    cout<<"Enter element to search for:"<<endl;
    cin>>x;

    int result = binarySearch(arr, 0, n-1, x);

    if(result==-1)
        cout<<"Element not found!"<<endl;
    else
        cout<<"Found at "<<result+1<<endl;
    return 0;      
} 
