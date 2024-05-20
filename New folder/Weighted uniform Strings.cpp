//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//
///*
// * Complete the 'weightedUniformStrings' function below.
// *
// * The function is expected to return a STRING_ARRAY.
// * The function accepts following parameters:
// *  1. STRING s
// *  2. INTEGER_ARRAY queries
// */
//
//int getValue(char s) {
//    static map<char, int> values;
//    if (values.empty()) {
//        for (char c = 'a'; c <= 'z'; ++c) {
//            values.insert(make_pair(c, c - 'a' + 1));
//        }
//    }
//    return values[s];
//}
//
//vector<string> weightedUniformStrings(string s, vector<int> queries) {
//    set<int> weights;
//    vector<string> result;
//
//    int currentWeight = 0;
//    char prevChar = '\0';
//
//    for (char c : s) {
//        if (c == prevChar) {
//            currentWeight += getValue(c);
//        } else {
//            currentWeight = getValue(c);
//            prevChar = c;
//        }
//        weights.insert(currentWeight);
//    }
//
//    for (int q : queries) {
//        if (weights.find(q) != weights.end()) {
//            result.push_back("Yes");
//        } else {
//            result.push_back("No");
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string s;
//    getline(cin, s);
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
//    vector<string> result = weightedUniformStrings(s, queries);
//
//    for (size_t i = 0; i < result.size(); i++) {
//        fout << result[i];
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
//    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
//        return !isspace(ch);
//    }));
//    return s;
//}
//
//string rtrim(const string &str) {
//    string s(str);
//    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), s.end());
//    return s;
//}
