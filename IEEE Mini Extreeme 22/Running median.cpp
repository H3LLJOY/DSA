//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//
///*
// * Complete the 'runningMedian' function below.
// *
// * The function is expected to return a DOUBLE_ARRAY.
// * The function accepts INTEGER_ARRAY a as parameter.
// */
//
//
////12
////4
////5
////3
////8
////7
//
//vector<double> runningMedian(vector<int> a) {
//    vector<double> result;
//    priority_queue<int> maxHeap;
//    priority_queue<int,vector<int>,greater<int>> minHeap;
//    for(int n:a){
//        if(maxHeap.empty() || n<=maxHeap.top()){ //todo maxheap eke pitipassata yanne kudainm
//            maxHeap.push(n);
//        }
//        else minHeap.push(n);  //todo wishalainm min heap eke pitipassata yanne
//
//        if(maxHeap.size()>minHeap.size()+1){
//            minHeap.push(maxHeap.top());
//            maxHeap.pop();
//        }
//        else if(minHeap.size()>maxHeap.size()){
//            maxHeap.push(minHeap.top());
//            minHeap.pop();
//        }
//        if(maxHeap.size()==minHeap.size()){
//            result.push_back( (maxHeap.top()+minHeap.top()) /2.0);
//        }
//        else result.push_back(maxHeap.top());
//    }
//    return result;
//
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string a_count_temp;
//    getline(cin, a_count_temp);
//
//    int a_count = stoi(ltrim(rtrim(a_count_temp)));
//
//    vector<int> a(a_count);
//
//    for (int i = 0; i < a_count; i++) {
//        string a_item_temp;
//        getline(cin, a_item_temp);
//
//        int a_item = stoi(ltrim(rtrim(a_item_temp)));
//
//        a[i] = a_item;
//    }
//
//    vector<double> result = runningMedian(a);
//
//    for (size_t i = 0; i < result.size(); i++) {
//        cout << result[i];
//
//        if (i != result.size() - 1) {
//            cout << "\n";
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
