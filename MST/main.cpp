#include <iostream>
#include <vector>
using namespace std;

void printMST(vector<int> parent,vector<vector<int>> graph){
    int vertices=graph.size();
    cout<<"Edge  Weight"<<endl;
    for(int i=1;i<vertices;i++){
        cout<<parent[i]<<"  "<<i<<"  "<<graph[i][parent[i]]<<endl;
    }
}


int minKey(vector<int> key,vector<bool> mstSet, int V){
    int min=INT_MAX;
    int min_index;
    for(int v=0;v<V;v++){
        if(!mstSet[v] && key[v] < min){ //if vertex is not added to mstSet and if it is minimum
            min=key[v];
            min_index=v;
        }
    }
    return min_index;
}

void primMST(vector<vector<int>> graph, int V){
    vector<int> parent(V); //Vector to store constructed minimum spanning tree
    vector<int> key(V,INT_MAX); //key values used to pick minimum weight edge in cut
    vector<bool> mstSet(V,false);

    key[0]=0;    //Make key 0 for the source vertex
    parent[0]=-1; //Root does snot have any parent

    for(int iteraion=0; iteraion < V - 1; iteraion++){
        int u= minKey(key,mstSet,V);
        mstSet[u]= true;

        for(int v=0;v<V;v++){
            if(graph[u][v] && mstSet[v]== false && graph[u][v]<key[v]){ //checkin that u and v are adjacent vertices and v is not visited yet
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }

    }
    printMST(parent,graph);

}

int main() {
    int V=5;
    //cin >>V;
    //cin.ignore();
    vector<vector<int>> graph=        {{0,2,0,6,0},
                                      {2,0,3,8,5},
                                      {0,3,0,0,7},
                                      {6,8,0,0,9},
                                      {0,5,7,9,0} ,
                                      };
    primMST(graph, V);
    return 0;
}
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <unordered_set>
//#include <algorithm>
//
//using namespace std;
//
//// Structure to represent an edge
//struct Edge {
//    int src, dest, weight;
//    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
//};
//
//// Comparator for priority queue
//struct CompareEdge {
//    bool operator()(const Edge& e1, const Edge& e2) {
//        return e1.weight > e2.weight;
//    }
//};
//
//// Class to represent a graph
//class Graph {
//private:
//    int V;
//    vector<vector<pair<int, int>>> adjList; // Adjacency list representation
//
//public:
//    Graph(int vertices) : V(vertices) {
//        adjList.resize(V);
//    }
//
//    // Function to add an edge to the graph
//    void addEdge(int src, int dest, int weight) {
//        adjList[src].push_back(make_pair(dest, weight));
//        adjList[dest].push_back(make_pair(src, weight)); // Graph is undirected
//    }
//
//    // Function to perform Prim's algorithm to find MST
//    vector<Edge> primMST(int startNode) {
//        // Priority queue to store edges
//        priority_queue<Edge, vector<Edge>, CompareEdge> pq;
//        vector<bool> inMST(V, false); // To track vertices already in MST
//        vector<Edge> mstEdges; // To store the edges of MST
//
//        // Add starting node to MST
//        inMST[startNode] = true;
//
//        // Add all edges connected to starting node to priority queue
//        for (pair<int, int> connectedEdge: adjList[startNode])
//            pq.push(Edge(startNode, connectedEdge.first, connectedEdge.second));
//
//
//
//        // <----- ADD YOUR CODE HERE ----->
//
//
//
//    while (!pq.empty()) {
//        Edge e = pq.top(); // Get the minimum weight edge
//        pq.pop();
//
//        int u = e.dest;
//
//        // If destination is already in MST, skip this edge
//        // <----- ADD YOUR CODE HERE ----->
//        if(!inMST[u]){
//            mstEdges.push_back(e);
//            inMST[u]= true;
//            for (pair<int, int> connectedEdge: adjList[u])
//                pq.push(Edge(u, connectedEdge.first, connectedEdge.second));
//        }
//
//        // Add edge to MST
//        // <----- ADD YOUR CODE HERE ----->
//
//
//
//        // Add all edges connected to u to priority queue
//        // <----- ADD YOUR CODE HERE ----->
//
//
//    }
//
//    return mstEdges;
//}
//
//// Function to print edges of MST ordered by minimum of edge.src and edge.dest
//void printMST(vector<Edge>& mstEdges) {
//    sort(mstEdges.begin(), mstEdges.end(), [](const Edge& e1, const Edge& e2) {
//        int min1 = min(e1.src, e1.dest);
//        int min2 = min(e2.src, e2.dest);
//        return min1 < min2 || (min1 == min2 && e1.src + e1.dest < e2.src + e2.dest);
//    });
//
//    for (const auto& edge : mstEdges) {
//        cout << "(" << min(edge.src, edge.dest) << ", " << max(edge.src, edge.dest) << ") - Weight: " << edge.weight << endl;
//    }
//}
//
//};
//
//int main() {
//    // Create a graph
//    Graph g(6);
//
//    // Add edges to the graph
//    g.addEdge(0, 1, 3);
//    g.addEdge(0, 5, 1);
//    g.addEdge(1, 2, 2);
//    g.addEdge(1, 3, 1);
//    g.addEdge(1, 4, 10);
//    g.addEdge(2, 3, 3);
//    g.addEdge(2, 5, 5);
//    g.addEdge(3, 4, 5);
//    g.addEdge(4, 5, 4);
//
//    int startNode; // Starting node for Prim's algorithm
//    cin >> startNode;
//
//    // Find minimum spanning tree using Prim's algorithm
//    vector<Edge> mstEdges = g.primMST(startNode);
//
//    // Print the edges of MST
//    g.printMST(mstEdges);
//
//    return 0;
//}