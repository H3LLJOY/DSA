#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;







void heapify(vector<int> &heap,int i,int size){
    int left=i*2+1;
    int right=i*2+2;
    int minimum;
    if(left<size && heap[i]>heap[left]){
        minimum=left;
    }
    else minimum=i;
    if(right<size && heap[minimum]>heap[right]){
        minimum=right;
    }
    if(i!=minimum){
        swap(heap[i],heap[minimum]);
        heapify(heap,minimum,size);
    }
}


void buildMinHeap(vector<int> &heap,int size){
    for(int i=(size/2)-1;i>=0;i--){
        heapify(heap,i,size);
    }
}

void insert(vector<int>&heap,int data,int size){
    heap.push_back(data);
    size++;
    buildMinHeap(heap,size);
}

void Delete(vector<int> &heap, int data, unsigned long long int size){
    int i=0;
    while(heap[i]!=data) i++;
    if (i == size) {

        return;
    }
    swap(heap[i],heap[size-1]);
    heap.pop_back();
    size--;
    for(int j=i;j>=0;j--)
        heapify(heap,j,size);

}



int main() {
    int q;
    cin>>q;
    cin.ignore();
    vector<int> Heap;

    for(int i=0;i<q;i++){
        string input;
        getline(cin,input);
        istringstream iss(input);
        int num;
        vector<int> nums;
        while(iss>>num){
            nums.push_back(num);
        }
        if(nums[0]==1){
            insert(Heap,nums[1],Heap.size());
        }
        else if(nums[0]==2){
            Delete(Heap,nums[1],Heap.size());
        }
        else cout<<Heap[0]<<endl;

    }
    return 0;
}
