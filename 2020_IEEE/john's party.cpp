#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int numOfPeopleToInvite(vector<vector<int>> adjList , vector<int> peopleWanted){
    int numOfInvites = 0;
    int totalPeople=adjList.size();
    vector<bool> invited(totalPeople, false); //range based for loops walin iterator eka aul yanwa pahaladi vector size eka wenas unoth
    for(int i=0;i<peopleWanted.size();i++){
       if(!invited[peopleWanted[i]]) {
           numOfInvites++;
           invited[peopleWanted[i]] = true;
           int bestFriend =adjList[peopleWanted[i]][0];

           if(!invited[bestFriend] && find(peopleWanted.begin(),peopleWanted.end(),bestFriend)==peopleWanted.end()){

                     peopleWanted.push_back(bestFriend);
           }

       }
    }

    cout<<endl;
    return numOfInvites;
}


















int main() {
    int N; //total num of students
    cin>>N;
    vector<vector<int>> adjList(N);
    int u;
    int v;
    for(int i=0;i<N;i++){
        cin>>u>>v;
        adjList[u-1].push_back(v-1);

    }
    int m; //Num of People jhon wants to invite for the party
    cin>>m;
    vector<int> people; //people whon john wants to invite
    int temp;
    for(int i=0;i<m;i++){
        cin>>temp;
        people.push_back(temp-1);
    }
//    for(auto x:adjList){
//        for(auto y:x){
//            cout<<y<<" ";
//        }
//        cout<<endl;
//    }
//    for(auto x:people){
//        cout<<x<<" ";
//    }
    cout<<numOfPeopleToInvite(adjList,people);
    return 0;
}