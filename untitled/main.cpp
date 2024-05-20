#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*A function to calculate the n'th factorial*/
int fact(int n){
    if(n==0) return 1;
    else if(n>0)
        return n*fact(n-1);
    return -1;
}



int main() {
    int num;
    cin>>num;
    vector<int> sums;
    int row=0;
    while(true){
        int sum=0;
        for(int column=0;column<=row && column<=4;column++){
            sum += fact(row) / (fact(column) * fact(row - column));
        }
        cout<<sum<<endl;
        if(sum>=num) break;
        else{
            sums.push_back(sum);
            row++;
        }
    }
    // int navigate=0;
    // while(sums[navigate]<=num){
    //     navigate++;
    // }
    // cout<<sums[navigate-1];
    int size=sums.size();
    cout<<sums[size-1];



    return 0;
}

