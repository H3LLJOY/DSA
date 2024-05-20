#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct machine{
    int trimpet;
    int trumput;
};

int CalculatePower(machine m , int numOfMachinesL , int numOfMachinesR){
    return ( (m.trimpet * numOfMachinesL) + (m.trumput * numOfMachinesR) );
}

int maxPower ( vector<machine> machines ,int numOfMachines ){
    vector<int> powerVec;
    vector<int> indexes(numOfMachines);

    for (int i = 0; i < numOfMachines; i++) {
        indexes[i] = i;
    }

// Permutation loop using while
    do{
        // Calculate power for the current permutation
        for(int n:indexes){
            cout<<n<<" ";
        }
        int power = 0;
        for (int i = 0; i < numOfMachines; i++) {
            int numOfMachinesL = i; // Number of machines to the left of the current machine
            int numOfMachinesR = numOfMachines - 1 - i; // Number of machines to the right of the current machine
            power += CalculatePower(machines[indexes[i]], numOfMachinesL, numOfMachinesR);
        }
        powerVec.push_back(power);
    } while  (next_permutation(indexes.begin(), indexes.end()));
    return *max_element(powerVec.begin(),powerVec.end());
}





int main() {
    int numOfMachines;
    cin>>numOfMachines;
    vector<machine> machines;
    for (int i=0 ; i<numOfMachines ; i++){
        machine temp;
        cin>>temp.trimpet>>temp.trumput;
        machines.push_back(temp);
    }
    cout<<maxPower(machines,numOfMachines);



    return 0;
}

