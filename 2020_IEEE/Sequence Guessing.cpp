//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <set>
//#include <algorithm>
//using namespace std;
//
//
//
//
//
//void guessSequence (vector<vector<int>> copies ){
//    set<int> result;
//    for(auto copy : copies){
//        for(auto val :copy){
//            result.insert(val);
//        }
//    }
//    for(int num : result){
//        cout<<num<<" ";
//    }
//}
//
//
//int main() {
//    int numOfCopies;
//    cin>>numOfCopies;
//    int numbersInALine;
//    vector<vector<int>> copies;
//    for(int i=0;i<numOfCopies;i++){
//        cin>>numbersInALine;
//        vector<int> copy;
//        for(int j=0;j<numbersInALine;j++){
//            int temp;
//            cin >> temp;
//            copy.push_back(temp);
//        }
//        copies.push_back(copy);
//
//    }
//    for(vector<int> copy :copies){
//        for(int number : copy){
//            cout<<number<<" ";
//        }
//        cout<<endl;
//    }
//    guessSequence(copies);
//
//
//    return 0;
//}
//
//
////    set<int> result;
////    for(auto copy : copies){
////        for(auto val :copy){
////            result.insert(val);
////        }
////    }
////    for(int num : result){
////        cout<<num<<" ";
////    }
//
//
//
//
//
//
////#include <iostream>
////#include <vector>
////#include <unordered_map>
////#include <unordered_set>
////#include <queue>
////#include <algorithm>
////
////std::vector<int> find_lexicographically_smallest_sequence(int n, std::vector<std::vector<int>>& sequences) {
////    // Step 1: Create a graph of all numbers and their dependencies
////    std::unordered_map<int, std::unordered_set<int>> graph;
////    std::unordered_map<int, int> indegree;
////
////    // Step 2: Populate the graph with edges based on sequences
////    for (const auto& seq : sequences) {
////        for (size_t i = 0; i < seq.size() - 1; ++i) {
////            if (graph[seq[i]].find(seq[i + 1]) == graph[seq[i]].end()) {
////                graph[seq[i]].insert(seq[i + 1]);
////                indegree[seq[i + 1]]++;
////            }
////        }
////    }
////
////    // Step 3: Find all nodes with zero indegree to start the topological sort
////    std::queue<int> zero_indegree;
////    for (const auto& node : graph) {
////        if (indegree[node.first] == 0) {
////            zero_indegree.push(node.first);
////        }
////    }
////
////    // Step 4: Perform topological sort to determine the smallest lexicographical order
////    std::vector<int> result;
////    while (!zero_indegree.empty()) {
////        std::vector<int> current;
////        while (!zero_indegree.empty()) {
////            current.push_back(zero_indegree.front());
////            zero_indegree.pop();
////        }
////        std::sort(current.begin(), current.end()); // Sort to ensure lexicographical order
////        for (int node : current) {
////            result.push_back(node);
////            for (int neighbor : graph[node]) {
////                indegree[neighbor]--;
////                if (indegree[neighbor] == 0) {
////                    zero_indegree.push(neighbor);
////                }
////            }
////        }
////    }
////
////    return result;
////}
////
////int main() {
////    int n;
////
////    std::cin >> n;
////
////    std::vector<std::vector<int>> sequences;
////    for (int i = 0; i < n; ++i) {
////        int k;
////
////        std::cin >> k;
////        std::vector<int> seq(k);
////
////        for (int j = 0; j < k; ++j) {
////            std::cin >> seq[j];
////        }
////        sequences.push_back(seq);
////    }
////
////    // Compute the result
////    std::vector<int> smallest_sequence = find_lexicographically_smallest_sequence(n, sequences);
////
////    for (int num : smallest_sequence) {
////        std::cout << num << " ";
////    }
////    std::cout << std::endl;
////
////    return 0;
////}
