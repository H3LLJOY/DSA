#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &list,vector<int> left,vector<int> right){
    int i=0;
    int j=0;
    int k=0;
    while(i<left.size() && j<right.size()){
        if(left[i]<right[j])
            list[k++]=left[i++];
        else
            list[k++]=right[j++];
    }
    while(i<left.size())
        list[k++]=left[i++];
    while(j<right.size())
        list[k++]=right[j++];
}

void mergeSort(vector<int> &list){
    if(list.size()<2) return;
    int midIndex = list.size()/2;
    vector<int> left(list.begin(),list.begin()+midIndex);
    vector<int> right(list.begin()+midIndex,list.end());
    mergeSort(left);
    mergeSort(right);
    merge(list,left,right);
}





int partition(vector<int> &vec, int lb,int ub){
    int pivot = vec[lb];
    int start = lb;
    int end = ub;
    while(start < end){
        while(start<=end && pivot>=vec[start])
            start++;
        while(start<= end && pivot<vec[end] )
            end--;
        if(start<end)
            swap(vec[start],vec[end]);
    }
    swap(vec[lb],vec[end]);
    return end;
}


void quickSort(vector<int> &vec,int lb,int ub){
    if(lb<ub){
        int pos = partition(vec,lb,ub);
        quickSort(vec,lb,pos-1);
        quickSort(vec,pos+1,ub);
    }
}




void bubbleSort(vector<int> &vec ){
    for(int i =0;i<vec.size();i++){
        for(int j=0;j<vec.size()-1;j++){
            if(vec[j]>vec[j+1])
                swap(vec[j],vec[j+1]);
        }
    }
}

void optimizedBubbleSort(vector<int> & vec){
    for(int i=0;i<vec.size();i++){
        bool flag =1;
        for(int j=0;j<vec.size()-i;j++){
            if(vec[j]>vec[j+1]) {
                swap(vec[j], vec[j + 1]);
                flag = 0;
            }
        }
        if(flag) break;
    }
}

void selectionSort(vector<int>& vec){
    for(int i=0;i<vec.size()-1;i++){
        int min_index=i;
        for(int j=i+1;j<vec.size();j++){
            if(vec[min_index] > vec[j])
                min_index = j;
        }
        swap(vec[i],vec[min_index]);
    }
}

void insertionSort(vector<int>& vec){
    for(int i=1;i<vec.size();i++){
        int currentI = vec[i];
        int j = i-1;
        while(j>=0 && vec[j]>currentI){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = currentI;

    }

}


int main() {
    vector<int> list = {22,-12,500,-123,42,0,2,3,6,5,7};
    //quickSort(list,0,list.size()-1);
    insertionSort(list);
    for(int num:list){
        cout<<num<<" ";
    }
    return 0;
}
