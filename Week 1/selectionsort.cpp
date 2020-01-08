#include <bits/stdc++.h>

using namespace std;

int minIndex(int a[], int i, int j) 
{ 
    if (i == j) 
        return i; 
  
    int k = minIndex(a, i + 1, j); 
   
    return (a[i] < a[k])? i : k; 
} 
  
void selectionSort(int a[], int n, int index = 0) 
{ 
     
    if (index == n) 
       return; 
   
    int k = minIndex(a, index, n-1); 
  
     
    if (k != index) 
       swap(a[k], a[index]); 
   
    selectionSort(a, n, index + 1); 
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

    selectionSort(arr,n);

    cout<<"Sorted array: "<<endl;
    cout<<endl;

    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}