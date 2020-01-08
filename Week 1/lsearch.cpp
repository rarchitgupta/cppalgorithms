#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lsearch(int arr[],int l,int r,int x)
{
    if(r<l)
        return -1;
    if(arr[l]==x)
        return l;

    if(arr[r]==x)
        return r;

    return lsearch(arr,l+1,r-1,x);        
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

    int result = lsearch(arr, 0, n-1, x);

    if(result==-1)
        cout<<"Element not found!"<<endl;
    else
        cout<<"Found at "<<result+1<<endl;
    return 0;
}