#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/


    Node *lca(Node *root, int v1,int v2) {
        vector<Node*> anc_v1;
        vector<Node*> anc_v2;


        if(root->data ==v1 || root->data==v2)
            return root;
        Node* temp1=root;
        Node* temp2=root;

        while(temp1->data != v1 && temp1){
            if(temp1->data >v1){
                anc_v1.push_back(temp1);
                temp1=temp1->left;
            }
            else if(temp1->data <v1){
                anc_v1.push_back(temp1);
                temp1=temp1->right;
            }
        }
        if(temp1)
            anc_v1.push_back(temp1);

        while(temp2->data != v2 && temp2){
            if(temp2->data >v2){
                anc_v2.push_back(temp2);
                temp2=temp2->left;
            }
            else if(temp2->data <v2){
                anc_v2.push_back(temp2);
                temp2=temp2->right;
            }
        }
        if(temp2)
                anc_v2.push_back(temp2);
        int sizeOfAncV1=anc_v1.size();
        int sizeOfAncV2=anc_v2.size();
        int j=(sizeOfAncV1>sizeOfAncV2)?sizeOfAncV2:sizeOfAncV1;
        int i=0;
        while(anc_v1[i]==anc_v2[i] && i<j){
            i++;
        }
        return (anc_v1[i-1]);
        //if(anc_v1[0]==anc_v2[0]) return anc_v1[0];






    }





}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);

    std::cout << ans->data;

    return 0;
}
