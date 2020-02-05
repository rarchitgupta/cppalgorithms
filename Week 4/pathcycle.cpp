#include <bits/stdc++.h>

using namespace std; 
  
class Graph 
{ 
    int V;
   
    list<int> *adj;    
public:

    Graph(int V)    //V = Number of vertices
    {
        this->V = V; 
        adj = new list<int>[V]; //new adjacency list of V vertices 
    }

    void addEdge(int v, int w)  
    { 
        adj[v].push_back(w); //Add w to v’s adjacency list. 
    }
    
    bool isReachable(int s, int d) 
    { 
        if (s == d) 
            return true; 
  
         
        bool *visited = new bool[V]; 
        for (int i = 0; i < V; i++) 
            visited[i] = false; 
   
        list<int> queue; 
  
         
        visited[s] = true; 
        queue.push_back(s); 
  
         
        list<int>::iterator i; 
  
        while (!queue.empty()) 
        { 
             
            s = queue.front(); 
            queue.pop_front(); 
  
             
            for (i = adj[s].begin(); i != adj[s].end(); ++i) 
            { 
                 
                if (*i == d) 
                    return true; 
   
                if (!visited[*i]) 
                { 
                    visited[*i] = true; 
                    queue.push_back(*i); 
                } 
            } 
        } 
       
        return false; 
    }


    bool isCyclicUtil(int v, bool visited[], bool *recStack) 
    { 
        if(visited[v] == false) 
        {    
            
            visited[v] = true; 
            recStack[v] = true; 
   
            list<int>::iterator i; 
            for(i = adj[v].begin(); i != adj[v].end(); ++i) 
            { 
                if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                    return true; 
                else if (recStack[*i]) 
                    return true; 
            } 
  
        } 
        recStack[v] = false;
        return false; 
    } 
  
    
    bool isCyclic() 
    {    
        bool *visited = new bool[V]; 
        bool *recStack = new bool[V]; 
        for(int i = 0; i < V; i++) 
        { 
            visited[i] = false; 
            recStack[i] = false; 
        } 
  
        for(int i = 0; i < V; i++) 
            if (isCyclicUtil(i, visited, recStack)) 
                return true; 
  
        return false; 
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

    int ch;
    cout<<"1. Find path between two vertices"<<endl;
    cout<<"2. Find cycle in graph"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Enter vertices to find path between: "<<endl;
                int u,v;
                cin>>u>>v;
    
                if(g.isReachable(u, v)) 
                    cout<<"There is a path from " << u << " to " << v <<endl; 
                else
                    cout<<"There is no path from " << u << " to " << v <<endl; 
                break;
        case 2: if(g.isCyclic()) 
                    cout <<"Graph contains cycle"<<endl; 
                else
                    cout <<"Graph doesn't contain cycle"<<endl;         
        default:break;    
    }
    return 0; 
} 