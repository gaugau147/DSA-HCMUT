#include <iostream>
#include <sstream>
using namespace std;

struct node{
    int data;
    node* next = NULL;
};

void printSingleLinkedList(node* pHead){
    node *pTemp;
    pTemp = pHead;
    while (pTemp != NULL){
        cout<<pTemp->data<<" ";
        pTemp = pTemp->next;
    }
}
void printCircularLinkedList(node* pHead){
    node *pTemp;
    pTemp = pHead;
    cout<<pTemp->data<<" ";
    pTemp = pTemp->next;
    cout<<pTemp->data<<" ";
    pTemp = pTemp->next;
    while (pTemp != pHead){
        cout<<pTemp->data<<" ";
        pTemp = pTemp->next;
    }
}
void printList(node* pHead){
    node *pTemp;
    pTemp = pHead;
    cout<<pTemp->data<<" ";
    pTemp = pTemp->next;
    cout<<pTemp->data<<" ";
    pTemp = pTemp->next;
    while (pTemp != NULL && pTemp != pHead){
        cout<<pTemp->data<<" ";
        pTemp = pTemp->next;
    }
}
node* searchList(node* pHead, int data){
    node *result;
    result = pHead;
    while (result->data != data && result != NULL){
        result = result->next;
    }
    if (result->data = data){
        return result;
    }
    else {
        return NULL;
    }
}
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
//Add 2 polynomial lists as in Question 4a
node *addPolyList(node *PolyList1, node *PolyList2){
    node *result, *head;
    result = new node;  //create a linked list as the result
    head = result;      //head is the head of the result list
    if (PolyList1==NULL && PolyList2 != NULL){
        return PolyList2;    //in case we reach the end of list 1, return list 2
    }
    else if (PolyList1 != NULL && PolyList2 == NULL){
        return PolyList1;   //in case we reach the end of list 2, return list 1
    }
    result->data = PolyList1->data+PolyList2->data;    //add data of 2 lists
    result->next = addPolyList(PolyList1->next, PolyList2->next);   //call a recursive function for next node of each list
    return head;    //return the head of the result linked list
}


//multiply each element of polynomial 1 with one element of polynomial 2
node *mulEachElementPolyList(node *PolyList1, node *PolyList2){
    node *result, *head;
    result = new node;
    head = result;
    if (PolyList1==NULL){
        return NULL;
    }
    result->data = PolyList1->data * PolyList2->data;
    result->next = mulEachElementPolyList(PolyList1->next, PolyList2);
    return head;
}

//shift right each element of the linked list n spots
node *shift(node *PolyList, int n){
    node *head;
    head = new node;
    if (n==0){
        return PolyList;
    }
    head->data = 0;
    head->next = shift(PolyList, n-1);
}

//multiplies 2 polynomials using 3 functions above
node *mulPolyList(node *PolyList1, node *PolyList2){
    node *result1, *result2, *result, *head;
    int counter = countList(PolyList2);
    int n = 0;
    if (n == counter){
        return NULL;    //in case we reach the end of the list
    }
    result = NULL;
    while (PolyList2 != NULL){
        //multiply list 1 with each element of list 2, then add the result to result list (shift left 1 spot each time)
        result = addPolyList(result, shift(mulEachElementPolyList(PolyList1, PolyList2), n));
        n+=1;
        PolyList2 = PolyList2->next;    //move to the next element of list 2 and return the loop
    }
    return result;
}
/*

int main() {
    int Poly1[5] = { 5, 8, 3, 2, 9 };
    int Poly2[5] = { 2, 0, 0, 1, 5 };
    node *PolyList1, *PolyList2, *pTail;
    PolyList1 = ConvertToLinkedList(Poly1,5);
    PolyList2 = ConvertToLinkedList(Poly2,5);
    pTail2 = PolyList2;
    while (pTail2->next != NULL){
        pTail2 = pTail2->next;
    }
    pTail2->next = PolyList2;

    printCircularLinkedList(PolyList2);
}
*/
void func1(node* head) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) {
            temp->next = head;
            return;
        }
        temp = temp->next;
    }
}
void nextHead(node **head){
    //node* temp = head;

    *head = *head->next;
    //delete(temp);
}
void f(int &a){
    a = a + 1;
}
int main() {
    /*int Poly1[5] = { 5, 8, 3, 2, 9 };
    node *PolyList1, *result;
    PolyList1 = ConvertToLinkedList(Poly1,5);

    printSingleLinkedList(PolyList1);
    cout<<"\n";
    /*
    func1(PolyList1);
    cout<<"\n";
    printCircularLinkedList(PolyList1);

    nextHead(&PolyList1);
    printList(PolyList1);
    */
    int x;
    x = 5;
    f(x);
    cout<<x;
}
