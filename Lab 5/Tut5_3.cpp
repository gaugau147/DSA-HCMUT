#include<iostream>
#include<sstream>
#define COUNT 10
using namespace std;

class treeNode {
public:
    int data;
    treeNode* left = NULL;
    treeNode* right = NULL;
    treeNode(int data);
};

treeNode::treeNode(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

void print2D(treeNode *root, int space){
    if (root == NULL){
        return;
    }
    space += COUNT;
    //Call a recursive function to print each node on the right
    print2D(root->right, space);
    cout<<endl;
    for (int i = COUNT; i < space; i++){
        cout<<" ";
    }
    cout<<root->data<<"\n";
    //Call a recursive function to print each node on the left
    print2D(root->left, space);
}
void printTree(treeNode *root){
    print2D(root, 0);
}

//recursive function insert a new node to BST
treeNode *recursiveInsert(treeNode*subroot, treeNode*newNode ) {
    //return subroot when we reach the end
    if (subroot==NULL){
        subroot = newNode;
        return subroot;
    }
    //traverse through the BST to find the location for new node
    else {
        if (subroot->data < newNode->data){
            subroot->right = recursiveInsert(subroot->right,newNode);
        }
        else if (subroot->data > newNode->data) {
            subroot->left = recursiveInsert(subroot->left, newNode);
        }
        //If the node is already exist, return
        else {
            return subroot;
        }
    }
}

//A function prints out the path from root to the node having searchedData
void printPath (treeNode* subroot, int searchedData ) {
    if (subroot == NULL){
        return;
    }
    else{
        while (subroot != NULL){
            if (subroot->data > searchedData){
                cout<<subroot->data<<" -> ";
                subroot = subroot->left;
            }
            else if (subroot->data < searchedData){
                cout<<subroot->data<<" -> ";
                subroot = subroot->right;
            }
            else {
                cout<<subroot->data<<"\n";
                return;
            }
        }
    }
}

//A function that print out all leaves of the tree via Breadth First Traverse
void printLeavesBFT (treeNode* root) {
    if (root == NULL){
        return;
    }
    else if (root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    else if (root->left == NULL && root->right != NULL){
        printLeavesBFT(root->right);
    }
    else if (root->left != NULL && root->right == NULL){
        printLeavesBFT(root->left);
    }
    else {
        printLeavesBFT(root->left);
        printLeavesBFT(root->right);
    }
}

//A function that print out all leaves of the tree via LNR
void printLeavesLNR (treeNode* subroot) {
    // YOUR CODE HERE
}

//A function that print out all leaves of the tree via NLR
void printLeavesNLR (treeNode* subroot) {
    // YOUR CODE HERE
}

int main(){
    treeNode *Head, *Temp1, *Temp2, *left, *right;
    //Initialize the BTS
    Temp1 = new treeNode(5);
    Head = Temp1;
    left = new treeNode(2);
    right = new treeNode(7);
    Head->left = left;
    Head->right = right;
    Temp1 = left;
    Temp2 = right;
    left = new treeNode(1);
    right = new treeNode(3);
    Temp1->left = left;
    Temp1->right = right;
    left = new treeNode(6);
    right = new treeNode(8);
    Temp2->left = left;
    Temp2->right = right;
    //printTree(Head);

    //Insert new node
    Temp1 = new treeNode(9);
    //cout<<"\n\n\n\n\n";
    recursiveInsert(Head, Temp1);
    printTree(Head);


    //Print the path to the node which has search data
    //printPath(Head, 9);
    //Print all leaves using BFT
    printLeavesBFT(Head);

}
