#include<iostream>
#include<sstream>
#include<stdbool.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Queue {
    int counter;
    Node *Front;
    Node *Rear;
};

Queue* createQueue(){
    Queue *result;
    result = new Queue;
    result->counter = 0;
    result->Front = NULL;
    result->Rear = NULL;
    return result;
}

void enQueue(Queue *&q, int data){
    if (q->counter == 0){
        Node *pTemp = new Node;
        q->Front = pTemp;
        q->Rear = pTemp;
        pTemp->data = data;
        pTemp->next = NULL;
    }
    else{
        Node *pTemp = new Node;
        pTemp->data = data;
        q->Rear->next = pTemp;
        q->Rear = pTemp;
        pTemp->next = NULL;
    }
    q->counter++;
}

void deQueue(Queue *&q){
    if (q->counter == 0){
        return;
    }
    else if (q->counter == 1){
        Node *pTemp = q->Front;
        q->Front = NULL;
        q->Rear = NULL;
        delete(pTemp);
    }
    else{
        Node *pTemp = q->Front;
        q->Front = pTemp->next;
        delete(pTemp);
    }
    q->counter--;
}

int QueueFront(Queue *q){
    if (q->counter == 0){
        return 0;
    }
    else {
        return q->Front->data;
    }
}

int QueueRear(Queue *q){
    if (q->counter == 0){
        return 0;
    }
    else {
        return q->Rear->data;
    }
}

bool isEmpty(Queue *q){
    if (q->Front == NULL){
        return true;
    }
    else {
        return false;
    }
}

bool isFull(Queue *q, int sizeQueue){
    if (q->counter >= sizeQueue){
        return true;
    }
    else {
        return false;
    }
}

void clearQueue(Queue *&q){
    while(!isEmpty(q)){
        deQueue(q);
    }
}

int sizeQueue(Queue *q){
    return q->counter;
}

void printQueue(Queue *q){
    if (q->counter == 0){
        cout<<"Queue is empty. ";
    }
    else{
        Node *pTemp;
        pTemp = q->Front;
        while (pTemp != NULL){
            cout<<pTemp->data<<" ";
            pTemp = pTemp->next;
        }
    }
}

int main() {
    Queue *Q;

    //1a
    Q = createQueue();

    //1b
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    printQueue(Q);
    cout<<"\n";

    //1c
    deQueue(Q);
    printQueue(Q);
    cout<<"\n";

    //1d
    cout<<QueueFront(Q);
    cout<<"\n";

    //1e
    cout<<QueueRear(Q);
    cout<<"\n";

    //1f
    cout<<isEmpty(Q);
    cout<<"\n";

    //1g
    cout<<isFull(Q, 100);
    cout<<"\n";

    //1i
    cout<<sizeQueue(Q);
    cout<<"\n";

    //1h
    clearQueue(Q);
    printQueue(Q);
    cout<<"\n";


}
