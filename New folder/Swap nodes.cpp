//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//vector<string> split(const string &);
//
///*
// * Complete the 'swapNodes' function below.
// *
// * The function is expected to return a 2D_INTEGER_ARRAY.
// * The function accepts following parameters:
// *  1. 2D_INTEGER_ARRAY indexes
// *  2. INTEGER_ARRAY queries
// */
//
//struct Node {
//    int index;
//    int depth;
//    struct Node* left;
//    struct Node* right;
//
//    Node(int index, int depth) : index(index), depth(depth), left(nullptr), right(nullptr) {}
//};
//
//
//
//Node* buildtree(vector<vector<int>>& indexes) {
//    Node* root = new Node(1, 1);
//    queue<Node*> q;
//    q.push(root);
//
//    for (auto& nodes : indexes) {
//        Node* current = q.front();
//        q.pop();
//
//        if (nodes[0] != -1) {
//            current->left = new Node(nodes[0], current->depth + 1);
//            q.push(current->left);
//        }
//
//        if (nodes[1] != -1) {
//            current->right = new Node(nodes[1], current->depth + 1);
//            q.push(current->right);
//        }
//    }
//
//    return root;
//}
//
//
//Node* swap(Node* root , int k){
//    if(!root) return nullptr;
//    if (root->depth==k){
//        Node* temp =root->right;
//        root->right = root->left;
//        root->left = temp;
//        return root;
//    }
//    root->left= swap(root->left,k);
//    root->right= swap(root->right,k);
//    return root;
//}
//
//
//
//
//int heightFinder(Node* root){
//    if(!root) return -1;
//    int leftHeight= 1 + heightFinder(root->left);
//    int rightHeight= 1 + heightFinder(root->right);
//    return max(leftHeight,rightHeight);
//}
//
//
//void storeInOrderResult(vector<int> &result ,Node* root){
//        if(!root) return;
//        storeInOrderResult(result,root->left);
//        result.push_back(root->index);
//        storeInOrderResult(result,root->right);
//}
//
//
//
//
//
//vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
//    vector<vector<int>> finalResult;
//    vector<int> result;
//    Node* root = buildtree(indexes);
//    int height = heightFinder(root);
//    for(int k:queries){
//        for(int i=k ;i<=height ; i=i+k){
//            swap(root,i);
//        }
//        storeInOrderResult(result,root);
//        finalResult.push_back(result);
//        result.clear();
//    }
//    return finalResult;
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string n_temp;
//    getline(cin, n_temp);
//
//    int n = stoi(ltrim(rtrim(n_temp)));
//
//    vector<vector<int>> indexes(n);
//
//    for (int i = 0; i < n; i++) {
//        indexes[i].resize(2);
//
//        string indexes_row_temp_temp;
//        getline(cin, indexes_row_temp_temp);
//
//        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));
//
//        for (int j = 0; j < 2; j++) {
//            int indexes_row_item = stoi(indexes_row_temp[j]);
//
//            indexes[i][j] = indexes_row_item;
//        }
//    }
//
//    string queries_count_temp;
//    getline(cin, queries_count_temp);
//
//    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));
//
//    vector<int> queries(queries_count);
//
//    for (int i = 0; i < queries_count; i++) {
//        string queries_item_temp;
//        getline(cin, queries_item_temp);
//
//        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));
//
//        queries[i] = queries_item;
//    }
//
//    vector<vector<int>> result = swapNodes(indexes, queries);
//
//    for (size_t i = 0; i < result.size(); i++) {
//        for (size_t j = 0; j < result[i].size(); j++) {
//            fout << result[i][j];
//
//            if (j != result[i].size() - 1) {
//                fout << " ";
//            }
//        }
//
//        if (i != result.size() - 1) {
//            fout << "\n";
//        }
//    }
//
//    fout << "\n";
//
//    fout.close();
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
//
