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

node *subPolyList(node *PolyList1, node *PolyList2){
    node *result, *head;
    result = new node;  //create a linked list as the result
    head = result;      //head is the head of the result list
    if (PolyList1==NULL && PolyList2 != NULL){
        result->data = 0-PolyList2->data;
        result->next = subPolyList(PolyList1, PolyList2->next);
    }       //in case we reach the end of list 1, return the negative of list 2
    else if (PolyList1 != NULL && PolyList2 == NULL){
        return PolyList1;   //in case we reach the end of list 2, return list 1
    }
    else if (PolyList1 == NULL && PolyList2 == NULL){
        return NULL;
    }
    else {
        result->data = PolyList1->data-PolyList2->data;    //add data of 2 lists
        result->next = subPolyList(PolyList1->next, PolyList2->next);   //call a recursive function for next node of each list
    }
    return head;    //return the head of the result linked list
}

int main() {
    int Poly1[5] = { 5, 8, 3, 2, 9 };
    int Poly2[7] = { 2, 0, 0, 1, 5, 9, 7 };
    node *PolyList1, *PolyList2, *result;
    PolyList1 = ConvertToLinkedList(Poly1,5);
    PolyList2 = ConvertToLinkedList(Poly2,7);
    printNode(PolyList1);
    cout<<"\n";
    printNode(PolyList2);
    cout<<"\n";
    result = subPolyList(PolyList1,PolyList2);
    printNode(result);
}

