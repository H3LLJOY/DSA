#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;

};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(!root) return ;
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if(!node){
        node = new  struct node();

        node->key=key;
        node->left=nullptr;
        node->right=nullptr;
    }
    else if(key<node->key){
        node->left=insertNode(node->left,key);
    }
    else if(key>node->key){
        node->right=insertNode(node->right,key);
    }
    return node;

}

struct node* findMax(struct node* root){
    while(root->right)
        root=root->right;
    return root;
}




// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(!root)
        return nullptr;
    if(root->key > key )
        root->left=deleteNode(root->left,key);
    else if(root->key < key )
        root->right=deleteNode(root->right,key);
        //case 1
    else{
        if(!root->left && !root->right){
            root=nullptr;
        }
            //case2
        else if(!root->left){
            root=root->right;
        }
        else if(!root->right){
            root=root->left;
        }
            //case 3
        else{
            struct node* temp=findMax(root->left);
            root->key=temp->key;
            root->left=deleteNode(root->left,temp->key);
        }

    }
    return root;

}

// Driver code
int main() {
    struct node *root = nullptr;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }

    traverseInOrder(root);
}