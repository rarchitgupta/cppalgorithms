#include <bits/stdc++.h> 

using namespace std; 
  
void addEdge(vector<int> adj[], int src, int dest) 
{ 
    adj[src].push_back(dest);  
} 
  
void displayGraph(vector<int> adj[], int v) 
{ 
    for (int i = 0; i < v; i++) { 
        cout << i << "--> "; 
        for (int j = 0; j < adj[i].size(); j++) 
            cout << adj[i][j] <<"  "; 
        cout <<endl; 
    } 
} 
   
void transposeGraph(vector<int> adj[], vector<int> transpose[], int v) 
{ 
    for (int i = 0; i < v; i++) 
        for (int j = 0; j < adj[i].size(); j++) 
            addEdge(transpose, adj[i][j], i); 
} 
  
int main() 
{ 
    int n;
    cout<<"Enter number of vertices in graph: "<<endl;
    cin>>n;
    vector<int> adj[n];

    cout<<"Add edges between graphs (Enter -1 to exit):"<<endl;
    int v1=0,v2=0;

    while(v1!=-1 && v2!=-1)
    {
        cout<<"Add edge: "<<endl;
        cin>>v1;
        cin>>v2;
        
        if(v1!=-1 && v2!=-1)
        {
            addEdge(adj,v1,v2);
        }
        else
            break;
        
    }
  
    vector<int> transpose[n]; 
    transposeGraph(adj, transpose, n); 
  
    displayGraph(transpose, n); 
  
    return 0; 
} 