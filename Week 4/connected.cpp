#include <bits/stdc++.h> 
using namespace std; 
  
class Graph 
{ 
    int V;    
    list<int> *adj;
  
    // A recursive function to print DFS starting from v 
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
  
        /* 
        If there exist mother vertex (or vertices) in given 
        graph, then v must be one (or one of them) 
  
        Now check if v is actually a mother vertex (or graph 
        has a mother vertex).  We basically check if every vertex 
        is reachable from v or not. 
  
        Reset all values in visited[] as false and do  
        DFS beginning from v to check if all vertices are 
        reachable from it or not. 
        */
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
        cout<<"Graph is connected"<<endl;
    else
        cout<<"Graph is not connected"<<endl;
        
}