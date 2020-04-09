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

//count the number of elements in a linked list
int countList(node *head){
    int counter=1;
    while (head->next != NULL){
        counter += 1;
        head = head->next;
    }
    return counter;
}
//traversal through the list and swap elements to sort list
void sortLinkedList(node *head){
    int counter;
    counter = countList(head);
    node *temp1 = head;
    node *temp2 = head;
    for (int i=0; i<counter; i++){
        for (int j=0; j<counter - 1; j++){
            if (temp1->data < temp2->data){
                int temp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp;
            }
            temp2 = temp2->next;
        }
        temp2 = head;
        temp1 = head->next;
        for (int k=0; k<i; k++){
            temp1 = temp1->next;
        }
    }

}

int main() {
    int List[5] = { 1, 4, 3, 7, 5};
    node *pHead;
    pHead = ConvertToLinkedList(List,5);
    printNode(pHead);
    cout<<"\n";
    sortLinkedList(pHead);
    printNode(pHead);
}
