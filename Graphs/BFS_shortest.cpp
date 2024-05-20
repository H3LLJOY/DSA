//#include <iostream>
//#include <vector>
//#include <queue>
//#include <unordered_map>
//#include <algorithm>
//
//using namespace std;
//
//// Function to perform BFS and find the shortest path
//vector<int> shortestPathBFS(vector<vector<int>>& graph, int start, int end) {
//    int numNodes = graph.size();
//
//    vector<int> visited(numNodes, false);
//    vector<int> parent(numNodes, -1);
//    queue<int> q;
//    q.push(start);
//    visited[start] = true;
//
//    while (!q.empty()) {
//        int currNode = q.front();
//        q.pop();
//
//        if (currNode == end) {
//            // Reconstruct the shortest path using the parent array
//            vector<int> shortestPath;
//            while (currNode != -1) {
//                shortestPath.push_back(currNode);
//                currNode = parent[currNode];
//            }
//            reverse(shortestPath.begin(), shortestPath.end());
//            return shortestPath;
//        }
//
//        for (int neighbor : graph[currNode]) {
//            if (!visited[neighbor]) {
//                visited[neighbor] = true;
//                parent[neighbor] = currNode;
//                q.push(neighbor);
//            }
//        }
//    }
//
//    // If no path is found, return an empty vector
//    return {};
//}
//
//int main() {
//    int numNodes = 6;
//    vector<vector<int>> graph(numNodes);
//    graph[0] = {2};
//    graph[1] = {0, 2, 3};
//    graph[2] = {0, 1};
//    graph[3] = {1, 5};
//    graph[4] = {2, 5};
//    graph[5] = {3, 4};
//
//    int source = 0;
//    int destination = 5;
//
//    vector<int> shortestPath = shortestPathBFS(graph, source, destination);
//
//    if (!shortestPath.empty()) {
//        cout << "Shortest Path from " << source << " to " << destination << ":" << endl;
//        for (int node : shortestPath) {
//            cout << node << " ";
//        }
//        cout << endl;
//    } else {
//        cout << "No path exists from " << source << " to " << destination << endl;
//    }
//
//    return 0;
//}