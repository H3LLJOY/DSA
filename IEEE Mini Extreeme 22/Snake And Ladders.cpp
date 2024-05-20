////#include <bits/stdc++.h>
////
////using namespace std;
////
////string ltrim(const string &);
////string rtrim(const string &);
////vector<string> split(const string &);
////
/////*
//// * Complete the 'quickestWayUp' function below.
//// *
//// * The function is expected to return an INTEGER.
//// * The function accepts following parameters:
//// *  1. 2D_INTEGER_ARRAY ladders
//// *  2. 2D_INTEGER_ARRAY snakes
//// */
////
////struct Ladder{
////    int start;
////    int end;
////    Ladder(int start ,int end): start(start),end(end){};
////};
////
////struct Snake{
////    int start;
////    int end;
////    Snake(int start ,int end): start(start),end(end){};
////};
////
//////TODO-kelinma 6k issarahata paninawada nattan eeta kalin ladder ekak thynawada balanna meka use karai
////int ladderAvailability(vector<Ladder> ladderVec ,int number){
////    //todo--1 idan 6k issarahata paniddi 7 kotuwata yanne.number kyala kynne 7.meken balannne 1 haa 7 athara wadima durakata yana ladders thynwd kyl
////    int max=0;
////    int maxHeightLadderIndex = 0;
////    for(int i=0;i<ladderVec.size();i++){
////        if(ladderVec[i].start < number && ladderVec[i].end > max) {
////            max=ladderVec[i].end;
////            maxHeightLadderIndex=i;
////        }
////    }
////    return maxHeightLadderIndex;
////}
////
//////TODO-this checks if a snakes mouth is available at a given position
////int snakeAvailabilty(vector<Snake> snakeVec ,int position){
////    for (Snake snake:snakeVec){
////        if(snake.start==position){
////            return 1;
////        }
////    }
////    return 0;
////}
////
////int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
////    int numOfRolls=0;
////    int position=1;
////    vector<Ladder> laddersVec;
////    vector<Snake> snakesVec;
//////        unordered_map<int,int> LaddersMap ;
//////        unordered_map<int,int> SnakesMap ;
////    for(vector<int> ladder : ladders){
////        //LaddersMap.insert(make_pair(ladder[0], ladder[1]));
////        laddersVec.push_back(Ladder(ladder[0],ladder[1]));
////    }
////    for(vector<int> snake : snakes){
////       snakesVec.push_back(Snake(snake[0],snake[1]));
////    }
////    while(position<100) {
////        if (ladderAvailability(laddersVec, position + 6)) {
////            numOfRolls++;
////            Ladder ladder = laddersVec[ladderAvailability(laddersVec, position + 6)];
////            position = ladder.end;
////        }
////        else {
////            int newPosition = position + 6;
////            while (newPosition > position) {
////                if (!snakeAvailabilty(snakesVec, newPosition)) {
////                    numOfRolls++;
////                    position = newPosition;
////                    break;
////                }
////                newPosition--;
////            }
////        }
////    }
////     return numOfRolls;
////}
////
////int main()
////{
////    ofstream fout(getenv("OUTPUT_PATH"));
////
////    string t_temp;
////    getline(cin, t_temp);
////
////    int t = stoi(ltrim(rtrim(t_temp)));
////
////    for (int t_itr = 0; t_itr < t; t_itr++) {
////        string n_temp;
////        getline(cin, n_temp);
////
////        int n = stoi(ltrim(rtrim(n_temp)));
////
////        vector<vector<int>> ladders(n);
////
////        for (int i = 0; i < n; i++) {
////            ladders[i].resize(2);
////
////            string ladders_row_temp_temp;
////            getline(cin, ladders_row_temp_temp);
////
////            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));
////
////            for (int j = 0; j < 2; j++) {
////                int ladders_row_item = stoi(ladders_row_temp[j]);
////
////                ladders[i][j] = ladders_row_item;
////            }
////        }
////
////        string m_temp;
////        getline(cin, m_temp);
////
////        int m = stoi(ltrim(rtrim(m_temp)));
////
////        vector<vector<int>> snakes(m);
////
////        for (int i = 0; i < m; i++) {
////            snakes[i].resize(2);
////
////            string snakes_row_temp_temp;
////            getline(cin, snakes_row_temp_temp);
////
////            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));
////
////            for (int j = 0; j < 2; j++) {
////                int snakes_row_item = stoi(snakes_row_temp[j]);
////
////                snakes[i][j] = snakes_row_item;
////            }
////        }
////
////        int result = quickestWayUp(ladders, snakes);
////
////        cout << result << "\n";
////    }
////
////    fout.close();
////
////    return 0;
////}
////
////string ltrim(const string &str) {
////    string s(str);
////
////    s.erase(
////            s.begin(),
////            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
////    );
////
////    return s;
////}
////
////string rtrim(const string &str) {
////    string s(str);
////
////    s.erase(
////            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
////            s.end()
////    );
////
////    return s;
////}
////
////vector<string> split(const string &str) {
////    vector<string> tokens;
////
////    string::size_type start = 0;
////    string::size_type end = 0;
////
////    while ((end = str.find(" ", start)) != string::npos) {
////        tokens.push_back(str.substr(start, end - start));
////
////        start = end + 1;
////    }
////
////    tokens.push_back(str.substr(start));
////
////    return tokens;
////}
//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//vector<string> split(const string &);
//
///*
// * Complete the 'quickestWayUp' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts following parameters:
// *  1. 2D_INTEGER_ARRAY ladders
// *  2. 2D_INTEGER_ARRAY snakes
// */
//
//int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
//    vector<int> adjlist(100);
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string t_temp;
//    getline(cin, t_temp);
//
//    int t = stoi(ltrim(rtrim(t_temp)));
//
//    for (int t_itr = 0; t_itr < t; t_itr++) {
//        string n_temp;
//        getline(cin, n_temp);
//
//        int n = stoi(ltrim(rtrim(n_temp)));
//
//        vector<vector<int>> ladders(n);
//
//        for (int i = 0; i < n; i++) {
//            ladders[i].resize(2);
//
//            string ladders_row_temp_temp;
//            getline(cin, ladders_row_temp_temp);
//
//            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));
//
//            for (int j = 0; j < 2; j++) {
//                int ladders_row_item = stoi(ladders_row_temp[j]);
//
//                ladders[i][j] = ladders_row_item;
//            }
//        }
//
//        string m_temp;
//        getline(cin, m_temp);
//
//        int m = stoi(ltrim(rtrim(m_temp)));
//
//        vector<vector<int>> snakes(m);
//
//        for (int i = 0; i < m; i++) {
//            snakes[i].resize(2);
//
//            string snakes_row_temp_temp;
//            getline(cin, snakes_row_temp_temp);
//
//            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));
//
//            for (int j = 0; j < 2; j++) {
//                int snakes_row_item = stoi(snakes_row_temp[j]);
//
//                snakes[i][j] = snakes_row_item;
//            }
//        }
//
//        int result = quickestWayUp(ladders, snakes);
//
//        fout << result << "\n";
//    }
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
 * Complete the 'quickestWayUp' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY ladders
 *  2. 2D_INTEGER_ARRAY snakes
 */
//
//struct Ladder{
//    int start;
//    int end;
//    Ladder(int start,int end):start(start),end(end){};
//};
//
//struct Snake{
//    int mouth;
//    int tail;
//    Snake(int mouth,int tail):mouth(mouth),tail(tail){};
//};
//
//void buildAdjList(vector<vector<int>> &adjList,vector<Ladder> ladderList,unordered_set<int> snakeList){
//    for(int i=0;i<100;i++){
//        if(snakeList.count(i)){
//            continue;
//        }
//        int j=i+1;
//        while(j !=i+6 && j<=99 ){
//            if(snakeList.count(j)){
//                j++;
//                continue;
//            }
//            adjList[i].push_back(j++);
//        }
//    }
//    for(auto s:ladderList){
//        adjList[s.start].push_back(s.end);
//    }
//}
//
//
//
//
//int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
//    vector<Ladder> ladderList;
////    vector<Snake> snakeList;
//    for(auto l:ladders){
//        ladderList.push_back(Ladder(l[0]-1,l[1]-1));
//    }
////    for(auto s:snakes){
////        snakeList.push_back(Snake(s[0],s[1]));
////    }
//    unordered_set<int> snakelist;
//    for(auto s:snakes){
//        snakelist.insert(s[0]-1);
//    }
//    vector<vector<int>> adjList(100);
//    buildAdjList(adjList,ladderList,snakelist);
//
//    //TODO BFS
//    vector<bool> visited(100, false);
//    queue<pair<int,int>> q;
//    q.push(make_pair(0,0));
//    while(!q.empty()){
//        auto [position,rolls]=q.front();
//        visited[position]=true;
//        q.pop();
//
//        if(position==99) return rolls;
//
//        for(int neighbour:adjList[position]){
//                if(!visited[neighbour]){
//                    visited[neighbour]=true;
//                    q.push(make_pair(neighbour,rolls+1));
//                }
//        }
//    }
//    return -1;
//}


int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes){
    vector<int> board(100,-1);
    for(auto l :ladders){
        board[l[0]-1]=l[1]-1;
    }
    for(auto s:snakes){
        board[s[0]-1]=s[1]-1;
    }
    vector<bool> visited(100,false);
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0] = true;
    while(!q.empty()){
        auto [position,rolls]=q.front();
        q.pop();
        if(position==99)
            return rolls;
        for(int i=1;i<=6;i++){
            int newPosition=position+i;
            if (newPosition <= 99 && !visited[newPosition]){
                visited[newPosition]= true;
                if (board[newPosition] != -1)
                    newPosition = board[newPosition];
                q.push({newPosition, rolls + 1});
            }
        }
    }
    return -1;
}





int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> ladders(n);

        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            string ladders_row_temp_temp;
            getline(cin, ladders_row_temp_temp);

            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int ladders_row_item = stoi(ladders_row_temp[j]);

                ladders[i][j] = ladders_row_item;
            }
        }

        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        vector<vector<int>> snakes(m);

        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            string snakes_row_temp_temp;
            getline(cin, snakes_row_temp_temp);

            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int snakes_row_item = stoi(snakes_row_temp[j]);

                snakes[i][j] = snakes_row_item;
            }
        }

        int result = quickestWayUp(ladders, snakes);

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
