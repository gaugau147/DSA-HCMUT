#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>
using namespace std;

struct Treenode {
    char data;
    Treenode *left;
    Treenode *right;
};
// Implement the constructor of Treenode
Treenode *newNode(char data) {
    Treenode *temp = new Treenode;
    temp->left = temp->right = NULL;
    temp->data = data;
    return temp;
}
// Check if a character is operand
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}
// Implement the CreateExampleTree() function
Treenode *CreateExampleTree(string s) {
    stack<Treenode *> temp;
    Treenode *tree1, *tree2, *tree3;

    // Traverse through the string
    for (int i = 0; i < s.length(); i++)
    {
        // if the char is operator, add it to stack
        if (isOperator(s[i]) == false)
        {
           tree1 = newNode(s[i]);
           temp.push(tree1);
        }
        // else: pop operator out of stack
        else
        {
           tree1 = newNode(s[i]);

           tree2 = temp.top();
           temp.pop();
           tree3 = temp.top();
           temp.pop();

           tree1->right = tree2;
           tree1->left = tree3;

           temp.push(tree1);
        }
    }
    tree1 = temp.top();
    temp.pop();
    return tree1;
}

void printTree(Treenode *tree) {
    if (tree == NULL)
        return;
    printTree(tree->left);
    cout << tree->data << " ";
    printTree(tree->right);

    return;
}

// Count number of nodes in the tree
int countNode(Treenode *root) {
    int count = 1;
    if (root->left != NULL)
        count += countNode(root->left);
    if (root->right != NULL)
        count += countNode(root->right);
    return count;
}

// Calculate the value of the expression tree
float computeTree(Treenode *root) {
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        stringstream ss;
        string stringData;
        ss << root->data;
        ss >> stringData;
        return atof(stringData.c_str());
    }

    float leftValue = computeTree(root->left);

    float rightValue = computeTree(root->right);

    if (root->data == '+')
    {
        return leftValue + rightValue;
    }
    if (root->data == '-')
    {
        return leftValue - rightValue;
    }
    if (root->data == '*')
    {
        return leftValue * rightValue;
    }
    if (root->data == '/')
    {
        return leftValue / rightValue;
    }
}

bool IsExpressionTree(Treenode *root)
{
    static bool flag;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data>=0 && root->data<=9)
        {
            flag = false;

        }
        return flag;
    }
    IsExpressionTree(root->left);
    IsExpressionTree(root->right);

    //return flag;
}

int main() {
    // Question 1a
    // The print function only for test, it doesn't print parentheses
    Treenode *root = NULL;

    root = CreateExampleTree("437*+534+/-6+");
    cout << "The expression tree: ";
    printTree(root);
    cout<<"\n";

    // Question 1c
    cout << "Number of nodes: " << countNode(root);
    cout<<"\n";

    // Question 1f
    cout << "The value of expression tree is: " << computeTree(root);
    cout<<"\n";
    // Question 1b
    cout<<IsExpressionTree(root);

}
