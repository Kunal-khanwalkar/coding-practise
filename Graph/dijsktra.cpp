#include<iostream> 
#include<vector>
#include<set>
using namespace std;
//#define V 9 
  

int minDistance(int dist[], bool sptSet[], int n) 
{ 
    int V = n;
    int min = INT_MAX;
    int min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  

void dijkstra(vector<vector<int>> graph, int src) 
{ 
    int V = graph.size();

    int dist[V]; 
  
    bool sptSet[V];  
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    dist[src] = 0; 
  
    for (int count = 0; count < V - 1; count++) { 

        int u = minDistance(dist, sptSet, V); 
        sptSet[u] = true; 
  
        for (int v = 0; v < V; v++)   
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 

    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 



void newdijkstra(vector<vector<int>> graph, int src)
{
    int n = graph.size();    
    vector<int> dist(n,INT_MAX);

    dist[src] = 0;
    set<int> visited;

    while(visited.size() < n)
    {
        int min_index;
        int min = INT_MAX;     
        for(int i=0;i<n;i++)
        {                
            if(!visited.count(i) && dist[i] <= min)
            {
                min = dist[i];
                min_index = i;
            }            
        }

        visited.insert(min_index);

        for(int i=0;i<n;i++)
        {
            if(visited.count(i) && graph[min_index][i] && dist[min_index] != INT_MAX && dist[i] > dist[min_index] + graph[min_index][i])
                dist[i] = dist[min_index] + graph[min_index][i];
        }

    }

    cout<<"Vertex\tDistance from source\n";
    for(int i=0;i<n;i++)
        cout<<i<<'\t'<<dist[i]<<'\n';
}




int main() 
{ 
    int n = 9;
  
    int graph[n][n] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  

    vector<vector<int>> mat;

    for(int i=0;i<n;i++)
        mat.push_back(vector<int>(graph[i], graph[i] + sizeof(graph[i])/sizeof(int)));


    //dijkstra(mat, 0); 
    newdijkstra(mat,0);
  
    return 0; 
} 