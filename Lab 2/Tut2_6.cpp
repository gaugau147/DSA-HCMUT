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

int countList(node *head){
    int counter=1;
    while (head->next != NULL){
        counter += 1;
        head = head->next;
    }
    return counter;
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

node* deleteNth(node* head, int n){
    node *result;
    int counter = countList(head);
    if (n==0){      //if n=0 delete the head and return a new list
        result = head->next;
        delete(head);
        return result;
    }
    else if (n<0 || n>counter){ //if n<0 or greater than the length of the list, do nothing
        return head;
    }
    else {
        int counter2 = 0;
        result = head;
        node *temp;
        while (counter2 != n-1){  //point result to the n-1 node
            result = result->next;
            counter2 += 1;
        }
        temp = result;
        result = result->next;
        temp->next = result->next;
        delete(result);
        return head;
    }
}

int main() {
    int Poly1[4] = { 4, -1, 10, 5 };
    node *PolyList1, *test;
    PolyList1 = ConvertToLinkedList(Poly1,4);
    printNode(PolyList1);
    cout<<"\n";
    test = deleteNth(PolyList1, 3);
    printNode(test);
}


