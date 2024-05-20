//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//class Graph {
//private:
//    int vertices;
//    vector<vector<int>> adjList;
//
//public:
//    Graph(int V) : vertices(V), adjList(V) {}
//
//    void addEdge(int u, int v) {
//        adjList[u].push_back(v);
//        adjList[v].push_back(u); // For an undirected graph
//    }
//
//    void dfs(int startVertex) {
//        vector<bool> visited(vertices, false);
//        stack<int> s;
//
//        s.push(startVertex);
//        visited[startVertex] = true;
//
//        while (!s.empty()) {
//            int currentVertex = s.top();
//            s.pop();
//            cout << currentVertex << " "; // Process the current vertex
//
//            for (int neighbor : adjList[currentVertex]) {
//                if (!visited[neighbor]) {
//                    s.push(neighbor);
//                    visited[neighbor] = true;
//                }
//            }
//        }
//    }
//};
//
//int main() {
//    Graph g(6); // Create a graph with 6 vertices
//
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 3);
//    g.addEdge(1, 4);
//    g.addEdge(2, 4);
//    g.addEdge(3, 4);
//    g.addEdge(3, 5);
//
//    cout << "DFS traversal starting from vertex 0:" << endl;
//    g.dfs(3);
//
//    return 0;
//}
//
////class graph{
////private:
////    int vertices;
////    int start;
////    vector<vector<int>> adjList;
////
////public:
////    graph(int v,int start):vertices(v),adjList(v),start(start) {}
////
////    void addEdge(int u,int v){
////        adjList[u].push_back(v);
////        adjList[v].push_back(u);
////    }
////
////    void DFS(){
////        stack<int> stk;
////        vector<bool> visited(vertices, false);
////        stk.push(start);
////        visited[start]= true;
////
////        while(!stk.empty()){
////            int currentNode=stk.top();
////            stk.pop();
////            cout<<"Current node is :"<<currentNode<<endl;
////            for(int neighbour:adjList[currentNode]){
////                if(!visited[neighbour]){
////                    stk.push(neighbour);
////                    visited[neighbour]= true;
////                }
////            }
////        }
////    }
////
////
////
////};
////int main() {
////    graph g(6,0); // Create a graph with 6 vertices
////
////    g.addEdge(0, 1);
////    g.addEdge(0, 2);
////    g.addEdge(1, 3);
////    g.addEdge(1, 4);
////    g.addEdge(2, 4);
////    g.addEdge(3, 4);
////    g.addEdge(3, 5);
////
////    cout << "DFS traversal starting from vertex 0:" << endl;
////    g.DFS();
////
////    return 0;
////}
