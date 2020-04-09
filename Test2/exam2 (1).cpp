#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>
using namespace std;

// void swap(int *a, int *b);

struct Treenode {
    char data;
    Treenode *left;
    Treenode *right;
};

Treenode *CreateExampleTree();
Treenode *newNode(char data);
bool isOperator(char c);
void printTree(Treenode *tree);
int countNode(Treenode *root);

float computeTree(Treenode *root);

int main() {
    //============Cau 1 . a===================
    Treenode *root = NULL;
    root = CreateExampleTree();
    cout << "Print expression tree:" << endl;
    printTree(root);
    cout << endl;

    //============Cau 1 . c===================
    cout << "Number of nodes: " << endl << countNode(root) << endl;

    //============Cau 1 . f===================
    cout << "The value of expression tree is: " << endl << computeTree(root) << endl;


    return 0;
}

Treenode *CreateExampleTree() {
   stack<Treenode *> tempStack;
   Treenode *tree1, *tree2, *tree3;

    char array[] = "437*+534+/-6+"; //Postfix order

    for (int i = 0; i < strlen(array); i++) {
       if (isOperator(array[i]) == false) {
           tree1 = newNode(array[i]);
           tempStack.push(tree1);
       } else {
           tree1 = newNode(array[i]);

           tree2 = tempStack.top();
           tempStack.pop();
           tree3 = tempStack.top();
           tempStack.pop();

           tree1->right = tree2;
           tree1->left = tree3;

           tempStack.push(tree1);
       }
   }
    tree1 = tempStack.top();
    tempStack.pop();

    return tree1;
}

Treenode *newNode(char data) {
    Treenode *temp = new Treenode;
    temp->left = temp->right = NULL;
    temp->data = data;
    return temp;
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') 
        return true; 
    return false; 
}

void printTree(Treenode *tree) {
    if (tree == NULL)
        return;
    printTree(tree->left);
    cout << tree->data << " ";
    printTree(tree->right);

    return;
}


int countNode(Treenode *root) {
    int count = 1;
    if (root->left != NULL)
        count += countNode(root->left);
    if (root->right != NULL)
        count += countNode(root->right);
    return count;
}



float computeTree(Treenode *root) {
    if (root == NULL)
        return 0;
    
    if (root->left == NULL && root->right == NULL) {
        stringstream ss;
        string stringData;
        ss << root->data;
        ss >> stringData;

        return atof(stringData.c_str());
    }
        

    float leftValue = computeTree(root->left);

    float rightValue = computeTree(root->right);

    if (root->data == '+')
        return leftValue + rightValue;

    if (root->data == '-')
        return leftValue - rightValue;

    if (root->data == '*')
        return leftValue * rightValue;
    
    if (root->data == '/')
        return leftValue / rightValue;
}









// float stringToFloat (string s);







// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     return;
// }


// float stringToFloat (string s) {
//     int retValue = 0;
//     if (s[0] != '-')
//         for (int i = 0; i < s.length(); i++)
//             retValue = retValue*10 + (int(s[i]-48));
//     else
//         for (int i = 1; i < s.length(); i++)
//         {
//             retValue = retValue*10 + (int(s[i])-48);  
//             retValue = retValue*-1; 
//         }

//     float floatData = (float) retValue;
//     return floatData;
// }