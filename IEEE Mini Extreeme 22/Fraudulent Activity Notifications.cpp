//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//vector<string> split(const string &);
//
///*
// * Complete the 'activityNotifications' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts following parameters:
// *  1. INTEGER_ARRAY expenditure
// *  2. INTEGER d
// */
//
//float medianForFiveDays(vector<int> payments){
//    sort(payments.begin(), payments.end());
//    if(payments.size()%2==1) return payments[payments.size()/2];
//    return (float)( payments[ payments.size()/2 ]+ payments[ (payments.size()/2) -1 ] )/2 ;
//}
//
//vector<int> extractByIndex(vector<int> vec,int start ,int end){
//    vector<int> result;
//    for(int i=start;i<=end ;i++){
//        result.push_back(vec[i]);
//    }
//    return result;
//}
//
//
//int activityNotifications(vector<int> expenditure, int d) {
//    int notifications =0 ;
//    int size = expenditure.size();
//    if(size<d) return notifications;
//    for(int i=0;i+d<size-1;i++){
//        int median= medianForFiveDays(extractByIndex(expenditure,i,i+d-1));
//        int TodaysPayment = expenditure[i+d];
//        if(median*2>= TodaysPayment) notifications++;
//    }
//    return notifications;
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string first_multiple_input_temp;
//    getline(cin, first_multiple_input_temp);
//
//    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
//
//    int n = stoi(first_multiple_input[0]);
//
//    int d = stoi(first_multiple_input[1]);
//
//    string expenditure_temp_temp;
//    getline(cin, expenditure_temp_temp);
//
//    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));
//
//    vector<int> expenditure(n);
//
//    for (int i = 0; i < n; i++) {
//        int expenditure_item = stoi(expenditure_temp[i]);
//
//        expenditure[i] = expenditure_item;
//    }
//
//    int result = activityNotifications(expenditure, d);
//
//    fout << result << "\n";
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

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

#include <iostream>
#include <vector>
#include <algorithm>

int findIndex(const std::vector<int>& arr, int ele) {
    int left = 0, right = arr.size() - 1, last;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == ele) return mid;
        if (arr[mid] > ele) {
            right = mid - 1;
            last = mid;
        } else {
            left = mid + 1;
            last = left;
        }
    }
    return last;
}


int threshold(std::vector<int>& arr, bool isOdd, int mid) {
    if (isOdd) return arr[mid] * 2;
    return arr[mid] + arr[mid + 1];
}

int activityNotifications(std::vector<int>& expenditure, int d) {
    vector<int> arr(expenditure.begin(), expenditure.begin() + d);
    sort(arr.begin(), arr.end());
    bool isOdd = d % 2 == 1;
    int mid = (d + 1) / 2 - 1;
    int notices = 0;
    for (int i = d, l = expenditure.size(); i < l; i++) {
        if (threshold(arr, isOdd, mid) <= expenditure[i]) {
            notices++;
        }
        arr.erase(find(arr.begin(),arr.end(),expenditure[i - d]));
        arr.insert(arr.begin() + findIndex(arr, expenditure[i]), expenditure[i]);
    }
    return notices;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

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
