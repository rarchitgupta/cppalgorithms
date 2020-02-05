#include <bits/stdc++.h> 
using namespace std; 
  
class Graph 
{ 
    int V;    
    list<int> *adj;
  
    
    void DFSUtil(int v, vector<bool> &visited)
    { 
        visited[v] = true; 

        list<int>::iterator i; 
        for (i = adj[v].begin(); i != adj[v].end(); ++i) 
            if (!visited[*i]) 
                DFSUtil(*i, visited); 
    }

public: 
    Graph(int V) 
    { 
        this->V = V; 
        adj = new list<int>[V]; 
    } 
    void addEdge(int v, int w)
    { 
        adj[v].push_back(w);
    } 
    
    int findMother() 
    { 
        vector <bool> visited(V, false); 
  
        // To store last finished vertex (or mother vertex) 
        int v = 0; 
  
        // Do a DFS traversal and find the last finished vertex   
        for (int i = 0; i < V; i++) 
        { 
            if (visited[i] == false) 
            { 
                DFSUtil(i, visited); 
                v = i; 
            } 
        } 
  
        fill(visited.begin(), visited.end(), false); 
        DFSUtil(v, visited);  
        for (int i=0; i<V; i++) 
            if (visited[i] == false) 
                return -1; 
  
        return v; 
    }    
}; 


int main() 
{ 
    int n;
    cout<<"Enter number of vertices in graph: "<<endl;
    cin>>n;

    Graph g(n);

    cout<<"Add edges between graphs (Enter -1 to exit):"<<endl;
    int v1=0,v2=0;

    while(v1!=-1 && v2!=-1)
    {
        cout<<"Add edge: "<<endl;
        cin>>v1;
        cin>>v2;
        
        if(v1!=-1 && v2!=-1)
        {
            g.addEdge(v1,v2);
        }
        else
            break;
        
    }

    int x=g.findMother();

    if(x!=-1)
        cout<<x<<" is the mother vertex"<<endl;
    else
        cout<<"Mother vertex not found"<<endl;
        
}
