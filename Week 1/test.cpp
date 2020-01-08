#include <bits/stdc++.h>

using namespace std;

int stringpermute(string a,int l,int r)
{
	if (l == r)  
        cout<<a<<endl;  
    else
    {  
        int i;  
        for (i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(a[l], a[i]);  
  
            // Recursion called  
            stringpermute(a, l+1, r);  
  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
}

int main()
{
	string x;
	cout<<"Enter string:"<<endl;
	cin>>x;

	int n=x.size();
	cout<<"Permutations: "<<endl;
	stringpermute(x,0,n-1);
}