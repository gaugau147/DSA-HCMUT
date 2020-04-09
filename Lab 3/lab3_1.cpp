#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class List {
    private:
        int count;
        Node *pHead;
    public:
        List();
        void addFirst(int);
        void addLast(int);
        void display();
        void addConstant(int nConst);
        void printPoly();
        List addPoly(List otherList);
        ~List();
};

List::List() {pHead = NULL; }

void List::addFirst(int newData) {
    Node *pTemp = new Node;
    pTemp->data = newData;
    pTemp->next = pHead;
    pHead = pTemp;
    count++;
}

void List::addLast(int newData) {
    if (pHead == NULL) { //crate first node if there's no node
        this->addFirst(newData);
    }
    else {
        Node *pTemp = pHead;
        while (pTemp->next != NULL) {
            pTemp = pTemp->next;
        }
        pTemp->next = new Node;
        pTemp->next->data = newData;
        pTemp->next->next = NULL;
    }
}

void List::display() {
    Node *pTemp = pHead;
    while (pTemp != NULL) {
        cout << pTemp->data << " ";
        pTemp = pTemp->next;
    }
    cout << endl;
}

void List::addConstant(int nConst) {
    Node *pTemp = pHead;
    while (pTemp->next != NULL) {
        pTemp = pTemp->next;
    }
    pTemp->data += nConst;
}

List List::addPoly(List otherList) {
    //Check if the other list has the same size
    Node *pTemp1 = pHead;
    Node *pTemp2 = otherList.pHead;
    int len1 = 0, len2 = 0;

    while (pTemp1 != NULL) {
        len1++;
        pTemp1 = pTemp1->next;
    }
    while (pTemp2 != NULL) {
        len2++;
        pTemp2 = pTemp2->next;
    }

    if (len1 > len2) {
        //Make len2 equal to len1
        for (int i = 0; i < len1 - len2; i++)
            otherList.addFirst(0);
    }
    else if (len1 < len2) {
        //make len1 equal to len2
        for (int i = 0; i < len2 - len1; i++) {
            this->addFirst(0);
        }
    }
    else;

    pTemp1 = pHead;
    pTemp2 = otherList.pHead;
    List result;
    while(pTemp1 != NULL) {
        result.addLast(pTemp1->data + pTemp2->data);
        // cout << pTemp1->data << " and " << pTemp2->data << endl;
        pTemp1 = pTemp1->next;
        pTemp2 = pTemp2->next; 
    }

    return result;
}

void List::printPoly() {
    Node *pTemp = pHead;
    
    int len = 0;
    while (pTemp != NULL) {
        len++;
        pTemp = pTemp->next;
    }
    // cout << "len: " << len << endl;

    int eff = len - 1;
    pTemp = pHead;
    while (pTemp->next != NULL) {
        if (pTemp->data != 0)
            if (pTemp->data != 1)
                cout << pTemp->data << "x^" << eff << " + ";
            else
                cout << "x^" << eff << " + ";
        pTemp = pTemp->next;
        eff--;
    }
    cout << pTemp->data << endl;
}

List::~List() {
    Node *pTemp = pHead;
    while (pTemp != NULL) {
        pTemp = pTemp->next;
        delete pHead;
        pHead = pTemp;
    }
}

int main() {
    List intList1;
    intList1.addFirst(1);
    intList1.addFirst(0);
    intList1.addFirst(1);
    intList1.addFirst(0);
    intList1.addFirst(5);
    // intList.addConstant(5);
    // intList1.display();
    intList1.printPoly();

    List intList2;
    intList2.addFirst(8);
    intList2.addFirst(0);
    intList2.addFirst(5);
    intList2.addFirst(3);
    // intList2.display();
    intList2.printPoly();


    List listAdded = intList1.addPoly(intList2);
    listAdded.printPoly();
    return 0;
}