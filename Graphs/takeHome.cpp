#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if (c_lib <= c_road || cities.empty()) {
        return n * (c_lib);
    }

    vector<vector<int>> adj_list(n + 1);
    for (const auto& city : cities) {
        adj_list[city[0]].push_back(city[1]);
        adj_list[city[1]].push_back(city[0]);
    }

    vector<bool> visited(n + 1, false);
    long total_cost = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int component_size = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int CurrentCity = q.front();
                q.pop();
                component_size++;

                for (int neighbor : adj_list[CurrentCity]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }

            total_cost += c_lib + c_road * (component_size - 1);
        }
    }

    return total_cost;
}







int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        cout << result << "\n";
    }

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
//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//vector<string> split(const string &);
//
///*
// * Complete the 'roadsAndLibraries' function below.
// *
// * The function is expected to return a LONG_INTEGER.
// * The function accepts following parameters:
// *  1. INTEGER n
// *  2. INTEGER c_lib
// *  3. INTEGER c_road
// *  4. 2D_INTEGER_ARRAY cities
// */
//
//void BFS(vector<vector<int>> adjList,int start,int n){
//    queue<int> q;
//
//    vector<bool> visited(n, false);
//    q.push(start);
//    visited[start-1]=true;
//
//    while(!q.empty()){
//        int currentCity=q.front();
//        q.pop();
//        cout<<currentCity;
//        for(int neighbour:adjList[currentCity-1]){
//            if(!visited[neighbour-1]){
//                q.push(neighbour);
//                visited[neighbour-1]= true;
//            }
//        }
//    }
//}
//
//void buildRoad(vector<vector<int>> &adjList, int city1, int city2){
//    adjList[city1-1].push_back(city2);
//    adjList[city2-1].push_back(city1);
//}
//
//
//
//long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
//    vector<vector<int>> adjList(n);
//    for(vector<int> road:cities){
//        buildRoad(adjList,road[0],road[1]);
//    }
//    BFS(adjList,1,n);
////    for(vector v1:adjList){
////        for(int city:v1){
////            cout<<city<<"->";
////        }
////        cout<<endl;
////    }
//
//    return 0;
//}
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
//        int c_lib = stoi(first_multiple_input[2]);
//
//        int c_road = stoi(first_multiple_input[3]);
//
//        vector<vector<int>> cities(m);
//
//        for (int i = 0; i < m; i++) {
//            cities[i].resize(2);
//
//            string cities_row_temp_temp;
//            getline(cin, cities_row_temp_temp);
//
//            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));
//
//            for (int j = 0; j < 2; j++) {
//                int cities_row_item = stoi(cities_row_temp[j]);
//
//                cities[i][j] = cities_row_item;
//            }
//        }
//
//        long result = roadsAndLibraries(n, c_lib, c_road, cities);
//
//        cout << result << "\n";
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
