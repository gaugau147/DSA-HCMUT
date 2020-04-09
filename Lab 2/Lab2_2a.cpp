#include <iostream>
#include <sstream>
using namespace std;

struct node{
    int data;
    node* next = NULL;
};

void printNode(node *Head){
    if (Head->next == NULL){
        cout<<Head->data<<" ";
        return;
    }
    else {
        cout<<Head->data<<" ";
        return (printNode(Head->next));
    }
}

int main() {
    int List[5] = { 1, 2, 3, 4, 5};
    node *pHead;
    pHead = ConvertToLinkedList(List,5);
    printNode(pHead);
}
