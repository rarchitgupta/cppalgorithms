#include <bits/stdc++.h>

using namespace std; 
  
class Graph 
{ 
    int V;
   
    list<int> *adj;    
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
    

    
    void BFS(int s) 
    { 
        
        bool *visited = new bool[V]; 
        for(int i = 0; i < V; i++) 
            visited[i] = false; 
  
        
            list<int> queue; 
  
        
        visited[s] = true; 
        queue.push_back(s); 
  
        
        list<int>::iterator i; 
  
        while(!queue.empty()) 
        { 
            
            s = queue.front(); 
            cout << s << " "; 
            queue.pop_front(); 
  
            
            for (i = adj[s].begin(); i != adj[s].end(); ++i) 
            { 
                if (!visited[*i]) 
                {    
                    visited[*i] = true; 
                    queue.push_back(*i); 
                } 
            } 
        } 
    }


    
    void DFSUtil(int v, bool visited[]) 
    { 
         
        visited[v] = true; 
        cout << v << " "; 
  
        
        list<int>::iterator i; 
        for (i = adj[v].begin(); i != adj[v].end(); ++i) 
            if (!visited[*i]) 
                DFSUtil(*i, visited); 
    } 
    
    void DFS(int v) 
    { 
        
        bool *visited = new bool[V]; 
        for (int i = 0; i < V; i++) 
            visited[i] = false; 
  
        
        DFSUtil(v, visited); 
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
    
    int x;
    cout<<"1. Breadth First Search: "<<endl;
    cout<<"2. Depth First Search: "<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Enter vertex to start BFS from: "<<endl;
                cin>>x;
                g.BFS(x);
                break;
        case 2: cout<<"Enter vertex to start DFS from: "<<endl;
                cin>>x;
                g.DFS(x);
                break;

        default:break;        
    }

    return 0; 
} 