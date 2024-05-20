////#include <cmath>
////#include <cstdio>
////#include <vector>
////#include <iostream>
////#include <algorithm>
////#include <queue>
////using namespace std;
////
////struct Pokemon{
////    int strength;
////    int team;
////    Pokemon(int strength,int team):strength(strength),team(team){}
////};
////
////
////bool ComparePoki(Pokemon a,Pokemon b){
////    return a.strength>b.strength;
////}
////
////void BattleOfPokemons (vector<Pokemon> teamA ,vector<Pokemon> teamB  ){
////    sort(teamA.begin(),teamA.end(), ComparePoki);
////    sort(teamB.begin(),teamB.end(), ComparePoki);
////    int alivePokisInA=teamA.size();
////    int alivePokisInB=teamB.size();
////    int i=1; //TODO-this is used to switch the battle between teams
//
////    while(alivePokisInA!=0 and alivePokisInB !=0) {
////        if(i%2==1) {
////            Pokemon pokiA = teamA[0];
////            if (pokiA.strength >= alivePokisInB) {
////                alivePokisInB = 0;
////                cout << pokiA.team << endl;
////                return;
////            }
////            teamB.erase(teamB.begin(), teamB.begin() + pokiA.strength);
////            alivePokisInB -= pokiA.strength;
////            i++;
////        }
////        else if(i%2==0) {
////            alivePokisInB = teamB.size();
////            Pokemon pokiB = teamB[0];
////            if (pokiB.strength >= alivePokisInA) {
////                alivePokisInA = 0;
////                cout << pokiB.team << endl;
////                return;
////            }
////            teamA.erase(teamA.begin(),teamA.begin()+pokiB.strength);
////            alivePokisInA -= pokiB.strength;
////            i++;
////        }
////    }
////
////}
////
////
////
////int main() {
////    int p,q,f;  //p-num of pokemeons q-num of teams f-num of quaries
////    cin>>p>>q>>f;
////    int strength,team;
////    vector<vector<Pokemon>> teams(q);   //teams 1,2,3 lesa atha but vector ekata dameemata -1 indexing use krmu.(i.e 0,1,2)
////    for(int i=0 ;i<p ;i++){
////        cin>>strength>>team;
////        Pokemon tempPoki=Pokemon(strength, team);
////        teams[team-1].push_back(tempPoki);
////    }
//////    vector<pair<int,int>> battles;
////    int x,y,z; //TODO x-action(1-adding pokemon to team z with y hitPoints)(2-battle with team y and z/y will always attack first)
////    for(int i=0 ; i<f ; i++){
////        cin>>x>>y>>z;
////        if(x==1){
////            teams[z-1].push_back(Pokemon(y,z));
////        }
////        else{
////            BattleOfPokemons(teams[y-1],teams[z-1]);
////        }
////    }
////
//////    for(auto Team:teams){
//////        for (auto poki:Team){
//////            cout<<poki.strength<<" ";
//////        }
//////        cout<<endl;
//////    }
////
//////    for(int i=0;i<q;i++){
//////        sort(teams[i].begin(),teams[i].end(), ComparePoki);
//////    }
//////
//////    for(const auto& Team:teams){
//////        for (auto poki:Team){
//////            cout<<poki.strength<<" ";
//////        }
//////        cout<<endl;
//////    }
//////
//////    for(auto battle:battles){
//////        cout<<battle.first<<"vs"<<battle.second<<endl;
//////    }
////
////
////
////    return 0;
////}
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//struct Pokemon{
//    int strength;
//    int team;
//    Pokemon(int strength,int team):strength(strength),team(team){}
//};
//
//
//bool ComparePoki(Pokemon a,Pokemon b){
//    return a.strength>b.strength;
//}
//
//void BattleOfPokemons (vector<Pokemon> teamA ,vector<Pokemon> teamB  ){
//    sort(teamA.begin(),teamA.end(), ComparePoki);
//    sort(teamB.begin(),teamB.end(), ComparePoki);
//    int alivePokisInA=teamA.size();
//    int alivePokisInB=teamB.size();
//    int i=1; //TODO-this is used to switch the battle between teams
//    int j=0; //TODO-j and k is used to access alive pokimens
//    int k=0;
//    while(alivePokisInA!=0 and alivePokisInB !=0) {
//        if(i%2==1) {
//            Pokemon pokiA = teamA[j];
//            if (pokiA.strength >= alivePokisInB) {
//                cout << pokiA.team << endl;
//                return;
//            }
//            alivePokisInB -= pokiA.strength;
//            k+=pokiA.strength;
//            //cout<<"k-"<<k<<endl;
//
//        }
//        else if(i%2==0) {
//            //alivePokisInB = teamB.size();
//            Pokemon pokiB = teamB[k];
//            if (pokiB.strength >= alivePokisInA) {
//                cout << pokiB.team << endl;
//                return;
//            }
//            alivePokisInA -= pokiB.strength;
//            j+=pokiB.strength;
//            //cout<<"j-"<<j<<endl;
//        }
//        i++;
//    }
//
//}
//
//
//
//int main() {
//    int p,q,f;  //p-num of pokemeons q-num of teams f-num of quaries
//    cin>>p>>q>>f;
//    int strength,team;
//    vector<vector<Pokemon>> teams(q);   //teams 1,2,3 lesa atha but vector ekata dameemata -1 indexing use krmu.(i.e 0,1,2)
//    for(int i=0 ;i<p ;i++){
//        cin>>strength>>team;
//        Pokemon tempPoki=Pokemon(strength, team);
//        teams[team-1].push_back(tempPoki);
//    }
//
//    int x,y,z; //TODO x-action(1-adding pokemon to team z with y hitPoints)(2-battle with team y and z/y will always attack first)
//    for(int i=0 ; i<f ; i++){
//        cin>>x>>y>>z;
//        if(x==1){
//            teams[z-1].push_back(Pokemon(y,z));
//        }
//        else{
//            BattleOfPokemons(teams[y-1],teams[z-1]);
//        }
//    }
//
////    for(auto Team:teams){
////        for (auto poki:Team){
////            cout<<poki.strength<<" ";
////        }
////        cout<<endl;
////    }
//
////    for(int i=0;i<q;i++){
////        sort(teams[i].begin(),teams[i].end(), ComparePoki);
////    }
////
////    for(const auto& Team:teams){
////        for (auto poki:Team){
////            cout<<poki.strength<<" ";
////        }
////        cout<<endl;
////    }
////
////    for(auto battle:battles){
////        cout<<battle.first<<"vs"<<battle.second<<endl;
////    }
//
//
//
//    return 0;
//}
