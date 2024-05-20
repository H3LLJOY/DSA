#include <iostream>
#include <vector>

void heapify(int *pInt, int i, int size);

using namespace std;
//void swap(int array[],int a ,int b){
//    int temp=array[a];
//    array[a]=array[b];
//    array[b]=temp;
//}

void swap(vector<int> &array,int a ,int b){
    int temp=array[a];
    array[a]=array[b];
    array[b]=temp;
}

//void Heapify(int array[],int i,int Heapsize){
//    int left=2*i+1;
//    int right=2*i+2;
//    int largest;
//    if(left<Heapsize && array[i]<array[left]){
//        largest=left;
//    }else largest=i;
//    if(right<Heapsize && array[largest]<array[right])
//        largest=right;
//    if(largest!=i){
//        swap(array,i,largest);
//        Heapify(array,largest,Heapsize);
//
//    }
//}

void Heapify(vector<int> &array,int i,int Heapsize){
    int left=2*i+1;
    int right=2*i+2;
    int largest;
    if(left<Heapsize && array[i]<array[left]){
        largest=left;
    }else largest=i;
    if(right<Heapsize && array[largest]<array[right])
        largest=right;
    if(largest!=i){
        swap(array,i,largest);
        Heapify(array,largest,Heapsize);

    }
}




//void BuildHeap(int array[],int HeapSize){
//    int lastInternalNode=(HeapSize/2)-1;
//    for (lastInternalNode;lastInternalNode>=0;lastInternalNode--)
//        Heapify(array,lastInternalNode,HeapSize);
//}
void BuildHeap(vector<int> &array,int HeapSize){
    int lastInternalNode=(HeapSize/2)-1;
    for (lastInternalNode;lastInternalNode>=0;lastInternalNode--)
        Heapify(array,lastInternalNode,HeapSize);
}

//void HeapSort(int array[],int size){
//      while(size>1) {
//          swap(array,0,size-1);
//          size--;
//          Heapify(array, 0, size);
//      }
//}
void HeapSort(vector<int> &array,int size){
    while(size>1) {
        swap(array,0,size-1);
        size--;
        Heapify(array, 0, size);
    }
}

//void heapify(int array[], int i, int size) {
//    int parent=(i-1)/2;
//    while(i>1 and array[parent]>array[i]){
//        swap(array,i,parent);
//        i=parent;
//    }
//
//}

void heapify(vector<int> &array, int i, int size) {
    int parent=(i-1)/2;
    if(i>1 and array[parent]<array[i]){
        swap(array,i,parent);
        i=parent;
        heapify(array,i,size);
    }

}




//void insert(int array[],int size,int value){
//    size++;
//    array[size-1]=value;
//    heapify(array,size-1,size);
//}
void insert(vector<int> &array,int &size,int value){
    size++;
    array[size-1]=value;
    heapify(array,size-1,size);
}
//
void Remove(vector<int> &array,int size){ //extract method ekama tmai meh
    swap(array,0,size-1);
    array.pop_back();
    size--;
    Heapify(array,0,size-1);
}





int main() {
    vector<int> arr={4,17,3,12,9,6};
//    int size=sizeof(arr)/sizeof(arr[0]);
    int size=arr.size();
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;

    BuildHeap(arr,size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

//    insert(arr,size,10);
//    cout<<endl;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout<<endl;
//
//
//
//    Remove(arr,size);
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }



    HeapSort(arr,size);
    cout<<endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
