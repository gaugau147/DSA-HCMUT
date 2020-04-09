#include<iostream>
#include<sstream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

//interface part
class List {
private:
    int count;
    Node* pHead;
public:
    List();
    void addFirst(int);
    void display();
    void addConstant(int nConst);
    void display(Node *Head);
    List addPolyList(List Poly);
    void addLast(int newdata);
    void printPoly();
    ~List();
};

//implementation part
List::List() {
    count = 0;
    pHead = NULL;
}

void List::addFirst(int newdata) {
    Node* pTemp = new Node;
    pTemp->data = newdata;
    pTemp->next = pHead;
    pHead = pTemp;
    count++;
}

void List::addLast(int newdata){
    Node *pTemp = pHead;
    //if there's no element in the list, return the head with new data
    if (pTemp == NULL){
        this->addFirst(newdata);
    }
    //else point pTemp to the last element and add another node after it
    else {
        while (pTemp->next != NULL){
            pTemp = pTemp->next;
        }
        pTemp->next = new Node;
        pTemp->next->data = newdata;
        pTemp->next->next = NULL;
    }
    count++;
}

void List::display() {
    Node* pTemp = pHead;
    while (pTemp!=NULL) {
        cout << pTemp->data << " ";
        pTemp = pTemp->next;
    }
    cout << endl;
}

List::~List() {
    Node* pTemp = pHead;
    while (pTemp!=NULL) {
        pTemp = pTemp->next;
        delete pHead;
        pHead = pTemp;
    }
}

void List::addConstant(int nConst) {
    pHead->data += nConst;
    return;
}

List List::addPolyList(List Poly) {
    List result;
    Node *pTemp1 = this->pHead;
    Node *pTemp2 = Poly.pHead;
    int n = 0;

    //until we reach the end of both lists
    while (pTemp1 != NULL || pTemp2 != NULL){
        // if we reach the end of list 1, add data of list 2 to result
        if (pTemp1 == NULL && pTemp2 != NULL){
            result.addLast(pTemp2->data);
            pTemp2 = pTemp2->next;
        }

        //if we reach the end of list 2, add data of list 1 to result
        else if (pTemp1 != NULL && pTemp2 == NULL){
            result.addLast(pTemp1->data);
            pTemp1 = pTemp1->next;
        }

        //else: add data of both list and add to result
        else{
            result.addLast(pTemp1->data + pTemp2->data);
            pTemp1 = pTemp1->next; //move ptemp to next node
            pTemp2 = pTemp2->next;
        }
        n++;
    }
    result.count = n;

    return result;
}

int main() {
    List Poly1, Poly2;
    // List result;
    Poly1.addFirst(1);
    Poly1.addFirst(0);
    Poly1.addFirst(1);
    Poly1.addFirst(0);
    Poly1.addFirst(5);
    Poly1.display();

    Poly2.addFirst(2);
    Poly2.addFirst(3);
    Poly2.addFirst(0);
    Poly2.addFirst(5);


    Poly2.display();

    // Chạy 1 trong 3 lệnh dưới đây thì nó chạy được
    // List result (Poly1.addPolyList(Poly2));
    List result = Poly1.addPolyList(Poly2);
    //List result {Poly1.addPolyList(Poly2)};
    result.display();
}

