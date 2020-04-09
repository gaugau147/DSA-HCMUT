#include<iostream>
#include<sstream>
#include<stdbool.h>
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

/*
Algorithm checkBST_recur (val subroot <BinaryNode>, ref min <DataType>, ref max <DataType>)
This algorithm check if the input subroot is a BST recursively
Pre subroot points to a root of the subtree
Post min and max are the smallest and largest value in the subtree
Return true if the subtree is a BST, false otherwise
*/
void checkBST_recur (bool &flag, treeNode *root){
    flag = true;
    //if root is null, return true
    if (root == NULL){
        return;
    }
    //if there is only one node, return true
    else if (root->left == NULL && root->right == NULL){
        return;
    }
    //if there's no node on the left, turn right
    else if (root->left == NULL && root->right != NULL){
        if (root->right->data > root->data){
            checkBST_recur(flag, root->right);
        }
        else {
            flag = false;
            return;
        }
    }
    //if there is no node on the right, turn left
    else if (root->right == NULL && root->left != NULL){
        if (root->left->data < root->data){
            checkBST_recur(flag, root->left);
        }
        else {
            flag = false;
            return;
        }
    }
    //if there are both left and right nodes
    else {
        if (root->left->data >= root->data || root->right->data <= root->data){
            flag = false;
            return;
        }
        else {
            treeNode *pTemp = root->left;
            if (pTemp->right == NULL){
                return;
            }
            while (pTemp->right != NULL){
                pTemp = pTemp->right;
            }
            if (pTemp->data > root->data){
                flag = false;
                return;
            }
            pTemp = root->right;
            if (pTemp->right == NULL){
                return;
            }
            while (pTemp->left != NULL){
                pTemp = pTemp->left;
            }
            if (pTemp->data < root->data){
                flag = false;
                return;
            }
            checkBST_recur(flag, root->left);
            checkBST_recur(flag, root->right);
        }
    }
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
    left = new treeNode(9);
    right = new treeNode(10);
    Temp2->left->left = left;
    Temp1->right->left = right;
    printTree(Head);
    bool flag;
    checkBST_recur(flag, Head);
    cout<<flag;

}
