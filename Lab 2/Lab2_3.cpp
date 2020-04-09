#include <iostream>
#include <sstream>
using namespace std;

struct node{
    int data;
    node* next = NULL;
};

node *ConvertToLinkedList(int List[], int Size){
    node *pHead, *pTemp, *pTemp2;
    if (Size==0){
        return 0;
    }
    else if (Size==1){
        pHead = new node;
        pHead->data = List[0];
        return pHead;
    }
    else {
        int i=0;

        pHead = new node;
        pHead->data = List[0];

        pTemp = new node;
        pTemp->data = List[1];
        pTemp->next = NULL;
        pHead->next = pTemp;

        for (i=2; i<Size; i++){
            pTemp2 = new node;
            pTemp->next = pTemp2;
            pTemp2->data = List[i];
            pTemp = pTemp2;
        }
        return pHead;
    }
}

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

void reverseList(node *&head){
    node *pHead;
    node *pTemp;

    //empty list
    if (head == NULL){
        return;
    }

    pHead = head;
    pTemp = head->next;

    //list has 1 element
    if (pTemp == NULL){
        return;
    }

    reverseList(pTemp);

    //
    pHead->next->next = pHead;
    pHead->next = NULL;
    head = pTemp;
    return;
}

int main() {
    int List[5] = { 1, 4, 3, 7, 5};
    node *pHead;
    pHead = ConvertToLinkedList(List,5);
    printNode(pHead);
    cout<<"\n";
    reverseList(pHead);
    printNode(pHead);
}
