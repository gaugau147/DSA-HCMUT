#include<iostream>
#include<sstream>
#include<stdbool.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Stack {
    int counter;
    Node *top;
};

Stack* createStack(){
    Stack *result;
    result = new Stack;
    result->counter = 0;
    result->top = NULL;
    return result;
}

void pushStack(Stack *&s, int data){
    Node *pTemp;
    if (s->counter == 0){
        pTemp = new Node;
        s->top = pTemp;
        pTemp->data = data;
        pTemp->next = NULL;
    }
    else{
        pTemp = new Node;
        pTemp->data = data;
        pTemp->next = s->top;
        s->top = pTemp;
    }
    s->counter++;
}

void popStack(Stack *&s){
    Node *pTemp = s->top;
    s->top = s->top->next;
    s->counter--;
    delete (pTemp);
}

int topStack(Stack *s){
    if (s->counter == 0){
        return 0;
    }
    else {
        return s->top->data;
    }
}

bool isEmpty(Stack *s){
    if (s->top == NULL){
        return true;
    }
    else {
        return false;
    }
}

bool isFull(Stack *s, int sizeStack){
    if (s->counter == sizeStack){
        return true;
    }
    else {
        return false;
    }
}

void clearStack (Stack *&s){
    while(!isEmpty(s)){
        popStack(s);
    }
}

int sizeStack(Stack *s){
    return s->counter;
}

void printStack(Stack *s){
    if (s->counter == 0){
        cout<<"Stack is empty. ";
    }
    else{
        Node *pTemp;
        pTemp = s->top;
        while (pTemp != NULL){
            cout<<pTemp->data<<" ";
            pTemp = pTemp->next;
        }
    }
}

int main() {
    Stack *s1;

    //1a
    s1 = createStack();

    //1b
    pushStack(s1, 5);
    pushStack(s1, 6);
    pushStack(s1, 7);
    printStack(s1);
    cout<<"\n";

    //1c
    popStack(s1);
    printStack(s1);
    cout<<"\n";

    //1d
    int n;
    n = topStack(s1);
    cout<<n;
    cout<<"\n";

    //1h
    int Size;
    Size = sizeStack(s1);
    cout<<Size;
    cout<<"\n";

    //1e
    bool check;
    check = isEmpty(s1);
    cout<<check;
    cout<<"\n";

    //1f
    bool check_full;
    check_full = isFull(s1, 100);
    cout<<check_full;
    cout<<"\n";

    //1g
    clearStack(s1);
    printStack(s1);

}
