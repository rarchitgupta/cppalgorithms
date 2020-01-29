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
    

    
    void BFS(int s) 
    { 
        //Mark all the vertices as not visited initially 
        bool *visited = new bool[V]; 
        for(int i = 0; i < V; i++) 
            visited[i] = false; 
  
        // Create a queue for BFS 
            list<int> queue; 
  
        // Mark the current node as visited and enqueue it 
        visited[s] = true; 
        queue.push_back(s); 
  
        // 'i' will be used to get all adjacent 
        // vertices of a vertex 
        list<int>::iterator i; 
  
        while(!queue.empty()) 
        { 
            // Dequeue a vertex from queue and print it 
            s = queue.front(); 
            cout << s << " "; 
            queue.pop_front(); 
  
            // Get all adjacent vertices of the dequeued 
            // vertex s. If a adjacent has not been visited,  
            // then mark it visited and enqueue it 
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
        // Mark the current node as visited and 
        // print it 
        visited[v] = true; 
        cout << v << " "; 
  
        // Recur for all the vertices adjacent 
        // to this vertex 
        list<int>::iterator i; 
        for (i = adj[v].begin(); i != adj[v].end(); ++i) 
            if (!visited[*i]) 
                DFSUtil(*i, visited); 
    } 
    // DFS traversal of the vertices reachable from v. 
    // It uses recursive DFSUtil() 
    void DFS(int v) 
    { 
        // Mark all the vertices as not visited 
        bool *visited = new bool[V]; 
        for (int i = 0; i < V; i++) 
            visited[i] = false; 
  
        // Call the recursive helper function 
        // to print DFS traversal 
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