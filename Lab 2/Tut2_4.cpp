#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node {
int data;
Node *next = NULL;
};

void printNode(Node *Head){
    if (Head->next == NULL){
        cout<<Head->data<<" ";
        return;
    }
    else {
        cout<<Head->data<<" ";
        return (printNode(Head->next));
    }
}

Node *deleteNth(Node *head, int n){
    Node *temp, *temp2;
    temp = head;
    int counter = 0;
    if (n==0){
        head = head->next;
        free(temp);
        return head;
    }
    else {
        while (temp != NULL){
            counter += 1;
            temp = temp->next;
        }
        if (counter > n){
            return head;
        }
        else {
            counter = 0;
            temp = head;
            while (counter < n){
                counter += 1;
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            return head;
        }
    }
}


int main() {
    Node *pHead, *pTemp, *pTail, *pNew;

    pHead = new Node;
    pHead->data = 3;

    pTemp = new Node;
    pTemp->data = 6;
    pHead->next = pTemp;

    pTemp = new Node;
    pTemp->data = 13;
    pHead->next->next = pTemp;

    pTail = new Node;
    pTail->data = 5;
    pTemp->next = pTail;

    pTail = new Node;
    pTail->data = 17;
    pTail->next = NULL;
    pTemp->next->next = pTail;

    pNew = new Node;
    pNew->data = 9;
    pNew->next = pHead;
    pHead = pNew;

    pNew = new Node;
    pNew->data = 15;
    pTail->next = pNew;
    pTail = pNew;

    Node *pTemp2;
    pNew = pHead;
    while (pNew->data != 17){
        pTemp2 = pNew;
        pNew = pNew->next;
    }
    pTemp2->next = pNew->next;
    delete(pNew);

    printNode(pHead);
    cout<<"\n";

    pTemp2 = pHead;
    while (pTemp2->next != pTemp){
        pTemp2 = pTemp2->next;
    }
    pTemp2->next = pTemp->next;
    delete(pTemp);

    printNode(pHead);
    cout<<"\n";
    //pHead = deleteNth(pHead, 0);
    //printNode(pHead);

}
