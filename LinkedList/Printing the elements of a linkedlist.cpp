//#include <bits/stdc++.h>
//
//using namespace std;
//
//class SinglyLinkedListNode {
//public:
//    int data;
//    SinglyLinkedListNode *next;
//
//    SinglyLinkedListNode(int node_data) {
//        this->data = node_data;
//        this->next = nullptr;
//    }
//};
//
//class SinglyLinkedList {
//public:
//    SinglyLinkedListNode *head;
//
//
//    SinglyLinkedList() {
//        this->head = nullptr;
//
//    }
//
//    void insert_node(int node_data) {
//        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);
//
//        if (!this->head) {
//            this->head = node;
//        } else {
//            SinglyLinkedListNode* temp =head;
//            while(temp->next){
//                temp=temp->next;
//            }
//            temp->next = node;
//        }
//
//    }
//};
//
//
//void free_singly_linked_list(SinglyLinkedListNode* node) {
//    while (node) {
//        SinglyLinkedListNode* temp = node;
//        node = node->next;
//
//        free(temp);
//    }
//}
//
//// Complete the printLinkedList function below.
//
///*
// * For your reference:
// *
// * SinglyLinkedListNode {
// *     int data;
// *     SinglyLinkedListNode* next;
// * };
// *
// */
//void printLinkedList(SinglyLinkedListNode* head) {
//    SinglyLinkedListNode* temp=head;
//    while(temp){
//        cout<<(temp->data)<<" ";
//        temp=temp->next;
//    }
//
//}
//
//int main()
//{
//    SinglyLinkedList* llist = new SinglyLinkedList();
//
//    int llist_count;
//    cin >> llist_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist_count; i++) {
//        int llist_item;
//        cin >> llist_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist->insert_node(llist_item);
//    }
//
//    printLinkedList(llist->head);
//
//    return 0;
//}
