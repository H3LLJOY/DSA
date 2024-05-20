#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


void countPaths(vector<vector<int>> roads,int n){
    long pathcount=0;
    if(roads[0][0]==0) cout<<0;
    int current=0;
    vector<bool> visited(n, false);
    stack<int> stk;
    stk.push(0);
    visited[0]= true;
    bool breaker=false;
    while(!stk.empty()){
            current=stk.top();
            stk.pop();
            if(current==n-1) {
                pathcount++;
                continue;

            }
            if(pathcount>1000000000L){
                cout<<"INFINITE PATHS";
                breaker= true;
                break;
            }
            for(int neighbour : roads[current]){
                    stk.push(neighbour);
                    visited[neighbour]=true;

        }
    }
    if(breaker)return;
    long moduloValue = 1000000000L;
    cout<<(pathcount)% moduloValue;
}








int main() {
    int n , m; //n-the integer number of cities m-Directed roads
    cin>>n>>m;
    vector<vector<int>> roads(n);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        roads[u-1].push_back(v-1);
    }
//    for(int i=0;i<roads.size();i++){
//        cout<<i<<" ";
//        for(int city:roads[i]){
//            cout<<city<<" ";
//        }
//        cout<<endl;
//    }
    countPaths(roads,n);
    return 0;
}
