#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */
//
//int cookies(int k, vector<int> A) {
//    if (A.empty()) {
//        return -1;
//    }
//    sort(A.begin(),A.end());
//    int size=A.size();
//    int count=0;
//    while(size>=1){
//        if(A[0]>=k) return count;
//        int sum=A[0]+2*A[1];
//        cout<<sum<<endl;
//        count++;
//        if(sum>=k)
//            return count;
//        else{
//            A.erase(A.begin(), A.begin() + 2);
//            for(int i : A){
//                cout<<i<<" ";
//            }
//            cout<<endl;
//            cout<<sum<<endl;
//            A.push_back(sum);
//
//            for(int i : A){
//                cout<<i<<" ";
//            }
//            sort(A.begin(),A.end());
//            size=A.size();
//        }
//    }
//    return -1;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
int cookies(int k, vector<int> A) {
    if (A.empty()) {
        return -1;
    }
    sort(A.begin(), A.end());
    int size = A.size();
    int count = 0;
    while (size >= 1) {
        if (A[0] >= k) return count;
        int sum = A[0] + 2 * A[1];
        cout << sum << endl;
        count++;
        if (sum >= k) return count;
        else {
            A.erase(A.begin(), A.begin() + 2);
            for (int i : A) {
                cout << i << " ";
            }
            cout << endl;
            cout << sum << endl;
            A.push_back(sum);

            for (int i : A) {
                cout << i << " ";
            }
            cout << endl;
            sort(A.begin(), A.end());
            size = A.size();
        }
    }
    return -1;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_A;
    getline(cin, first_multiple_input_A);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_A));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_A_A;
    getline(cin, A_A_A);

    vector<string> A_A = split(rtrim(A_A_A));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_A[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

    cout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

