#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */


int hashfunc(char c) {
//    return abs(c - 'a'+1);
    if(isupper(c)) {
        return abs(c - 'A' + 1); // Hash code for capital letters starting from 1
    } else {
        return abs(c - 'a' + 27); // Hash code for lowercase letters starting from 27
    }
}

bool isEmpty(vector<int>hashTable,int hash){
    if(hashTable[hash]) return false;
    else return true;
}




string twoStrings(string s1, string s2) {
    vector<int> hashTable(52);
    for(char letter:s1){
        int hash= hashfunc(letter);
        hashTable[hash]=letter;
    }
    bool result= false;
    for(char letter:s2){
        int hash= hashfunc(letter);
        if(!isEmpty(hashTable,hash)){
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

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
