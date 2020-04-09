#include <iostream>
#include <sstream>
using namespace std;


struct node {
int data;
node *next = NULL;
};

int myMaxFunc(node* head, int maxVal) {
    if (head->next==NULL){
        return maxVal;
    }
    else {
        if (head->data>maxVal){
            maxVal = head->data;
        }
        return myMaxFunc(head->next, maxVal);
    }
}

int main(){
    node *pHead, *pTail;
    node *a, *b, *c, *d, *e;
    pHead = new node;
    pTail = new node;
    a = new node;
    b = new node;
    c = new node;
    d = new node;
    e = new node;
    pHead->data = -11;
    pHead->next = a;
    a->data = 5;
    a->next = b;
    b->data = 9;
    b->next = c;
    c->data = 3;
    c->next = d;
    d->data = 100;
    d->next = e;
    e->data = 2;
    e->next = pTail;
    pTail->data = 7;
    pTail->next = NULL;
    int n=0;
    cout<<"The max value in this linked list is: "<<myMaxFunc(pHead,n);
}
