#include <iostream>
#include <vector>
using namespace std;

//int vertexWithShortestDistance(vector<bool> considered , vector<int> distance , int V){
//    int min=INT_MAX;
//    int min_vertex;
//    for(int vertex =0; vertex < V; vertex++){
//        if(!considered[vertex] && distance[vertex] < min){
//            min_vertex=vertex;
//            min=distance[vertex];
//        }
//    }
//    return min_vertex;
//}
//
//void printShortestPaths(int src,vector<int> distance){
//    cout<<"Source             Vertice      distance"<<endl;
//    cout<<"-----------------------------------------"<<endl;
//    for(int i=0;i<distance.size();i++){
//        cout<<src<<"             "<<i<<"      "<<distance[i]<<endl;
//    }
//}
//
//
//void dijkstra(vector<vector<int>> graph ,int src){
//    int V=graph.size(); //numofVertices
//    vector<int> distance(V,INT_MAX);
//    vector<bool> considered(V, false);
//    distance[src]=0;
//
//    for(int i=1;i<=V-1;i++){
//        int u= vertexWithShortestDistance(considered,distance,V);
//        considered[u]= true;
//        for(int v=0;v<V;v++){
//            if(!considered[v] && graph[u][v] && distance[u]+graph[u][v]<distance[v]){
//                distance[v]=distance[u]+graph[u][v];
//            }
//        }
//    }
//    for(auto d:distance){
//        cout<<d<<" ";
//    }
//    cout<<endl;
//    printShortestPaths(src,distance);
//}

int verticeWithShortestDistance(vector<bool> considered, vector<int> distances, int V){
    int min=INT_MAX;
    int minIndex;
    for(int v=0;v<V;v++){
        if(!considered[v] && distances[v]<min){
            min=distances[v];
            minIndex=v;
        }
    }
    return minIndex;
}


void printDijkstra(int src,vector<int> distances){
    cout<<"source vertex"<<"  destination vertex"<<"      distance"<<endl;
    for(int i=0;i<distances.size();i++){
        cout<<src<<"       "<<i<<"    "<<distances[i]<<endl;
    }
}


void dijkstra(vector<vector<int>> graph,int src){
    int V=graph.size();
    vector<bool> considered(V,false);
    vector<int> distances(V,INT_MAX);
    distances[src]=0;
    for(int i=1;i<V;i++){
        int u= verticeWithShortestDistance(considered, distances, V);
        considered[u]=true;
        for(int v=0;v<V;v++){
            if(!considered[v] && graph[u][v] && distances[u]+graph[u][v]<distances[v]){
                distances[v]=distances[u]+graph[u][v];
            }
        }
    }
    printDijkstra(src,distances);

}

int vertexWithMinEdge( vector<int> edgeWeight,vector<bool> Added,int V){
    int min=INT_MAX;
    int min_index;
    for(int v=0 ; v<V ; v++){
        if(!Added[v] && edgeWeight[v]<min){
            min=edgeWeight[v];
            min_index=v;
        }
    }
    return min_index;
}


void printMST(vector<int> parent,vector<vector<int>> graph){
    int vertices=graph.size();
    cout<<"Edge  Weight"<<endl;
    for(int i=1;i<vertices;i++){
        cout<<parent[i]<<"  "<<i<<"  "<<graph[i][parent[i]]<<endl;
    }
}

void primMST(vector<vector<int>> graph,int src){
    int V=graph.size();
    vector<int> parent(V); //Vector to store constructed minimum spanning tree
    vector<int> edgeWeight(V,INT_MAX); //key values used to pick minimum weight edge in cut
    vector<bool> Added(V, false);
    edgeWeight[src]=0;
    parent[src]=-1;

    for(int  iteration =0 ;iteration<V-1;iteration++){
        int u= vertexWithMinEdge(edgeWeight,Added,V);
        Added[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v] && !Added[v] && graph[u][v]<edgeWeight[v]){
                parent[v]=u;
                edgeWeight[v]=graph[u][v];
            }
        }
    }
    printMST(parent,graph);
}







void bellmanFord(vector<vector<int>> graph,int src){
    int V=graph.size();
    vector<int> distances(V,INT_MAX);
    distances[src]=0;
    for(int i=1;i<=V-1;i++){
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(graph[u][v] && distances[u]+graph[u][v]<distances[v]){
                    distances[v]=distances[u]+graph[u][v];
                }
            }
        }
    }
    for(int u=0;u<V;u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && distances[u] + graph[u][v] < distances[v]) {
                cout << "graph contains negative cycle" << endl;
            }
        }
    }
    printDijkstra(src,distances);
}










int main() {
    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                  { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                  { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                  { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                  { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                  { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                  { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                  { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                  { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // Function call
    primMST(graph, 0);
    return 0;
}
