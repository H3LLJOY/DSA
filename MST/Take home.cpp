//////#include <bits/stdc++.h>
//////
//////using namespace std;
//////
//////string ltrim(const string &);
//////string rtrim(const string &);
//////vector<string> split(const string &);
//////
///////*
////// * Complete the 'bfs' function below.
////// *
////// * The function is expected to return an INTEGER_ARRAY.
////// * The function accepts following parameters:
////// *  1. INTEGER n
////// *  2. INTEGER m
////// *  3. 2D_INTEGER_ARRAY edges
////// *  4. INTEGER s
////// */
//////
//////bool valueFinder(vector<int> vec,int value){
//////    auto it = find(vec.begin(), vec.end(), value);
//////    if (it != vec.end()) return true;
//////    else return false;
//////}
//////
//////
//////int pathFromNeighbours(vector<vector<int>> adjList ,int value,int s){
//////    int pathCost=6;
//////    for(int neighbour:adjList[s]){
//////        if(valueFinder(adjList[neighbour],value)){
//////            pathCost+=6;
//////            return pathCost;
//////        }
//////    }
//////    pathFromNeighbours(adjList,value,)
//////}
//////
//////
//////
//////vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) { //n-number of nodes m-number of edges s-starting node
//////    vector<int> distances(n-1,-1);
//////    vector<vector<int>> adjList(n);
//////    for(vector<int> edge:edges){
//////        adjList[edge[0]-1].push_back(edge[1]-1);
//////        adjList[edge[1]-1].push_back(edge[0]-1);
//////    }
//////    queue<int> q;
//////    vector<bool> visited(n,false);
//////
//////    q.push(s);
//////    visited[s-1]=true;
//////    int pathCost=0;
//////    while(!q.empty()){
//////        pathCost+=6;
//////        int currentNode=q.front();
//////        q.pop();
//////        for(int neighbour:adjList[currentNode-1]){
//////            if(!visited[neighbour-1]){
//////                visited[neighbour-1]=true;
//////                q.push(neighbour);
//////                distances[neighbour-1]=pathCost;
//////            }
//////        }
//////    }
////////    for(int i=0;i<n;i++){
////////        if(!visited[i]){
////////            distances.push_back(-1);
////////        }
////////    }
//////
//////
//////
//////
////////    for(int i=1;i<=n;i++){
////////        if(i==s) continue;
////////        if(valueFinder(adjList[s],i)){
////////            distances.push_back(6);
////////        }
////////        else if(valueFinder()){
////////        }
////////    }
//////
//////
//////    return distances;
//////}
//////
//////int main()
//////{
//////    string q_temp;
//////    getline(cin, q_temp);
//////
//////    int q = stoi(ltrim(rtrim(q_temp)));
//////
//////    for (int q_itr = 0; q_itr < q; q_itr++) {
//////        string first_multiple_input_temp;
//////        getline(cin, first_multiple_input_temp);
//////
//////        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
//////
//////        int n = stoi(first_multiple_input[0]);
//////
//////        int m = stoi(first_multiple_input[1]);
//////
//////        vector<vector<int>> edges(m);
//////
//////        for (int i = 0; i < m; i++) {
//////            edges[i].resize(2);
//////
//////            string edges_row_temp_temp;
//////            getline(cin, edges_row_temp_temp);
//////
//////            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));
//////
//////            for (int j = 0; j < 2; j++) {
//////                int edges_row_item = stoi(edges_row_temp[j]);
//////
//////                edges[i][j] = edges_row_item;
//////            }
//////        }
//////
//////        string s_temp;
//////        getline(cin, s_temp);
//////
//////        int s = stoi(ltrim(rtrim(s_temp)));
//////
//////        vector<int> result = bfs(n, m, edges, s);
//////
//////        for (size_t i = 0; i < result.size(); i++) {
//////            cout << result[i];
//////
//////            if (i != result.size() - 1) {
//////                cout << " ";
//////            }
//////        }
//////
//////        cout << "\n";
//////    }
//////
//////    return 0;
//////}
//////
//////string ltrim(const string &str) {
//////    string s(str);
//////
//////    s.erase(
//////            s.begin(),
//////            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//////    );
//////
//////    return s;
//////}
//////
//////string rtrim(const string &str) {
//////    string s(str);
//////
//////    s.erase(
//////            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//////            s.end()
//////    );
//////
//////    return s;
//////}
//////
//////vector<string> split(const string &str) {
//////    vector<string> tokens;
//////
//////    string::size_type start = 0;
//////    string::size_type end = 0;
//////
//////    while ((end = str.find(" ", start)) != string::npos) {
//////        tokens.push_back(str.substr(start, end - start));
//////
//////        start = end + 1;
//////    }
//////
//////    tokens.push_back(str.substr(start));
//////
//////    return tokens;
//////}
//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//vector<string> split(const string &);
//
///*
// * Complete the 'bfs' function below.
// *
// * The function is expected to return an INTEGER_ARRAY.
// * The function accepts following parameters:
// *  1. INTEGER n
// *  2. INTEGER m
// *  3. 2D_INTEGER_ARRAY edges
// *  4. INTEGER s
// */
//
//using namespace std;
//
//vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
//////   // n - number of nodes, m - number of edges, edges - list of edges, s - starting node
//////   vector<int> distances(n-1, -1); // distances from starting node to all other nodes (initialized to -1)
//////   vector<vector<int>> adjList(n); // adjacency list to represent the graph
////
//////   // Create the adjacency list
//////   for (vector<int> edge : edges) {
//////     adjList[edge[0] - 1].push_back(edge[1] - 1);
//////     adjList[edge[1] - 1].push_back(edge[0] - 1); // Undirected graph (if directed, remove this line)
//////   }
////
//////   queue<int> q;
//////   vector<bool> visited(n, false); // visited nodes
////
//////   q.push(s - 1); // Enqueue starting node (adjust index if nodes start from 0)
//////   visited[s - 1] = true;
////
//////   int pathCost = 0;
//////   while (!q.empty()) {
//////     pathCost += 6; // Update path cost if needed (modify for different distance calculations)
//////     int currentNode = q.front();
//////     q.pop();
////
//////     for (int neighbour : adjList[currentNode]) {
//////       if (!visited[neighbour]) {
//////         visited[neighbour] = true;
//////         q.push(neighbour);
//////         distances[neighbour-1] = pathCost; // Update distance for the neighbour
//////       }
//////       else{
//////           if (pathCost<distances[neighbour]) distances[neighbour] = pathCost;
//////       }
//////     }
//////   }
////
//////   return distances;
////// n - number of nodes, m - number of edges, edges - list of edges, s - starting node
//    // n - number of nodes, m - number of edges, edges - list of edges, s - starting node
//
//    vector<int> distances(n - 1, -1); // distances from starting node to all other nodes (excluding itself, size n-1)
//    vector<vector<int>> adjList(n); // adjacency list to represent the graph
//
//    // Create the adjacency list
//    for (vector<int> edge : edges) {
//        adjList[edge[0] - 1].push_back(edge[1] - 1); // Adjust for 0-based indexing (if nodes start from 0, remove -1)
//        adjList[edge[1] - 1].push_back(edge[0] - 1); // Undirected graph (if directed, remove this line)
//    }
//
//    queue<int> q;
//    vector<bool> visited(n, false); // visited nodes
//
//    q.push(s - 1); // Enqueue starting node (adjust index if nodes start from 0)
//    visited[s - 1] = true;
//
//    int pathCost = 0;
//    while (!q.empty()) {
//        pathCost += 6; // Update path cost if needed (modify for different distance calculations)
//        int currentNode = q.front();
//        q.pop();
//
//        for (int neighbour : adjList[currentNode]) {
//            if (!visited[neighbour]) {
//                visited[neighbour] = true;
//                q.push(neighbour);
//                 cout << "Checking distance for neighbour: " << neighbour << " with index: " << neighbour - (s - 1) << endl;
//                distances[neighbour - (s - 1)] = pathCost; // Update distance for the neighbour (adjust index)
//            } else {
//                // Update distance for unreachable nodes (optional)
//                if (pathCost < distances[neighbour - (s - 1)]) {  // Update only if shorter path found
//                    distances[neighbour - (s - 1)] = pathCost;
//                }
//            }
//        }
//    }
//
//    return distances;
//}
//
//
//int main()
//{
//    string q_temp;
//    getline(cin, q_temp);
//
//    int q = stoi(ltrim(rtrim(q_temp)));
//
//    for (int q_itr = 0; q_itr < q; q_itr++) {
//        string first_multiple_input_temp;
//        getline(cin, first_multiple_input_temp);
//
//        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
//
//        int n = stoi(first_multiple_input[0]);
//
//        int m = stoi(first_multiple_input[1]);
//
//        vector<vector<int>> edges(m);
//
//        for (int i = 0; i < m; i++) {
//            edges[i].resize(2);
//
//            string edges_row_temp_temp;
//            getline(cin, edges_row_temp_temp);
//
//            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));
//
//            for (int j = 0; j < 2; j++) {
//                int edges_row_item = stoi(edges_row_temp[j]);
//
//                edges[i][j] = edges_row_item;
//            }
//        }
//
//        string s_temp;
//        getline(cin, s_temp);
//
//        int s = stoi(ltrim(rtrim(s_temp)));
//
//        vector<int> result = bfs(n, m, edges, s);
//
//        for (size_t i = 0; i < result.size(); i++) {
//            cout << result[i];
//
//            if (i != result.size() - 1) {
//                cout << " ";
//            }
//        }
//
//        cout << "\n";
//    }
//
//    return 0;
//}
//
//string ltrim(const string &str) {
//    string s(str);
//
//    s.erase(
//            s.begin(),
//            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//    );
//
//    return s;
//}
//
//string rtrim(const string &str) {
//    string s(str);
//
//    s.erase(
//            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//            s.end()
//    );
//
//    return s;
//}
//
//vector<string> split(const string &str) {
//    vector<string> tokens;
//
//    string::size_type start = 0;
//    string::size_type end = 0;
//
//    while ((end = str.find(" ", start)) != string::npos) {
//        tokens.push_back(str.substr(start, end - start));
//
//        start = end + 1;
//    }
//
//    tokens.push_back(str.substr(start));
//
//    return tokens;
//}
