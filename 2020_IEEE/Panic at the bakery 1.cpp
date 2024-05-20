#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


struct Stuffing {
    int amountLeft;
    int gramsPerBun;
    int gramsOfFlourPerBun;
    int sellingPricePerBun;
};

//TODO--this returns maximum number of buns that can be made with a stuffing under not exceeding flourAmount

int numOfMaxBuns(Stuffing stuff,int &flourUsage,int flourAmount){

    if(stuff.gramsOfFlourPerBun > flourAmount-flourUsage) return 0; //ithiriwela thyna piti walata wada bun 1k hadanna piti ynwnm bun hadanna ba
    int numOfBuns = stuff.amountLeft / stuff.gramsPerBun;
    flourUsage = flourUsage + numOfBuns * stuff.gramsOfFlourPerBun;
    int bunsToReduce=0;
    int tempFlourUsage = flourUsage;
    while(tempFlourUsage>flourAmount){ //100,100
        bunsToReduce++; //4
        tempFlourUsage = flourUsage;
        tempFlourUsage = tempFlourUsage - bunsToReduce * stuff.gramsOfFlourPerBun;
    }
    //cout<<numOfBuns-bunsToReduce<<endl;
    return numOfBuns-bunsToReduce;
}

int maxProfit(int flourAmount,int numOfStuffings,vector<Stuffing> stuffings){
    vector<int> profits;
    for(int i=0 ;i<numOfStuffings;i++){
        int flourUsage = 0;
        int numOfBuns = numOfMaxBuns(stuffings[i],flourUsage,flourAmount);
        //flourUsage = numOfBuns * stuffings[i].gramsOfFlourPerBun;
        int profit = numOfBuns * stuffings[i].sellingPricePerBun;
        for(int j=0 ; j<numOfStuffings ;j++){
            if(j==i) continue;
            numOfBuns = numOfMaxBuns(stuffings[j],flourUsage,flourAmount);
            //flourUsage += numOfBuns * stuffings[j].gramsOfFlourPerBun;
            profit += numOfBuns*stuffings[j].sellingPricePerBun;
        }
        profits.push_back(profit);
    }

    return *max_element(profits.begin(),profits.end());
}



int main() {
    int flourAmount;
    int numOfStuffings;
    cin >> flourAmount >> numOfStuffings;
    vector<Stuffing> stuffings;
    for(int i=0 ; i < numOfStuffings ; i++){
        Stuffing temp;
        cin>>temp.amountLeft>>temp.gramsPerBun>>temp.gramsOfFlourPerBun>>temp.sellingPricePerBun;
        stuffings.push_back(temp);
    }
//    for(Stuffing s : stuffings){
//        cout<<s.amountLeft<<" "<<s.gramsPerBun<<" "<<s.gramsOfFlourPerBun<<" "<<s.sellingPricePerBun<<endl;
//    }
    cout<<maxProfit(flourAmount,numOfStuffings,stuffings);
//    Stuffing s;
//    s.amountLeft=50;
//    s.gramsPerBun=10;
//    s.gramsOfFlourPerBun=100;
//    s.sellingPricePerBun=100;
//    cout<<numOfMaxBuns(s,150,300);
    return 0;
}
