#include"UnrolledLinkedList.h"

void UnrolledLinkedList::add(int val) {
	if (size1 == 0){                    //if the Linked list is empty, create the first node
        Node *pTemp = new Node(this->nodeSize);
        pTemp->next = NULL;
        pTemp->add(val);
        this->head = pTemp;
        this->tail = pTemp;
        this->numOfNodes++;
	}
	else{                               //else: the Linked list is not empty
        Node *pTemp = this->head;
        while (pTemp->next != NULL){    //point pTemp to the last Node
            pTemp = pTemp->next;
        }
        if ((!pTemp->isFull())){        //if pTemp is not full, add value
            pTemp->add(val);
        }
        else {                          //if pTemp is full, create a new Node and move last elements of the last Node to the new Node
            Node* pTemp2 = new Node(this->nodeSize);
            pTemp->next = pTemp2;
            pTemp2->prev = pTemp;
            pTemp2->next = NULL;
            pTemp2->numElements = 0;

            int i = pTemp->getHalfNodeSize()-1;
            while (i>0){                //move n/2-1 elements down (n is the max number of elements)
                pTemp2->add(pTemp->elements[pTemp->numElements-i]);
                pTemp->removeAt(pTemp->numElements-i);
                i--;
            }
            pTemp2->add(val);
            this->tail = pTemp2;
            this->numOfNodes++;
        }
	}
	size1++;
}

int UnrolledLinkedList::getAt(int pos) {
	if (pos < 0 || pos >= size1){
		throw "IndexOutOfBoundsException"; // check whether pos is valid or not
	}
	else {
        if (this->size1 == 0){              //return 0 if linked list is empty
            return 0;
        }
        else{
            int m = pos+1;
            int n = 1, i;
            Node *pTemp = this->head;
            while (pTemp != NULL){
                for (i=0; i<pTemp->numElements; i++){
                    if (m == n){
                        goto theEnd;        //break when we reach the pos
                    }
                    n++;
                }
                pTemp = pTemp->next;
            }
            theEnd:
            return pTemp->elements[i];
        }
	}
	return 0;
}

void UnrolledLinkedList::setAt(int pos, int val) {
	if (pos < 0 || pos >= size1)
		throw "IndexOutOfBoundsException"; // check whether pos is valid or not
	else {
        if (this->size1 == 0){
            return;
        }
        else {
            int m = pos+1;                  //just like getAt() function, but change the value instead of returning it
            int n = 1, i;
            Node *pTemp = this->head;
            while (pTemp != NULL){
                for (i=0; i<pTemp->numElements; i++){
                    if (m == n){
                        goto theEnd;    //break when we reach the pos
                    }
                    n++;
                }
                pTemp = pTemp->next;
            }
            theEnd:
            pTemp->elements[i] = val;
        }
	}
}


void UnrolledLinkedList::insertAt(int pos, int val) {
	if (pos < 0 || pos >= size1)
		throw "IndexOutOfBoundsException"; // check whether pos is valid or not
	else if (size1 == 0 && pos == 0){      //if the Linked list is empty and pos = 0, create the first node and add the val
        Node *pTemp = new Node(this->nodeSize);
        pTemp->next = NULL;
        pTemp->add(val);
        this->head = pTemp;
        this->tail = pTemp;
        this->numOfNodes++;
        size1++;
	}
	else{                                   //else: the Linked list is not empty
        int m = pos+1;
        int n = 1, i;
        Node *pTemp = this->head;
        while (pTemp != NULL){
            for (i=0; i<pTemp->numElements; i++){
                if (m == n){
                    goto theEnd;            //break when we reach the pos
                }
                n++;
            }
            pTemp = pTemp->next;
        }

        theEnd:                             //now pTemp is pointing to the Node includes pos and i is the pos index
        if (!(pTemp->isFull())){            //if pTemp is not full, add value
            pTemp->insertAt(i, val);
        }
        else {                              //if pTemp is full, create a new Node and move last elements of the previous Node to the new Node
            Node *pTemp2 = new Node(this->nodeSize);
            if (pTemp->next == NULL){
                pTemp2->next = NULL;
                pTemp->next = pTemp2;
                pTemp2->prev = pTemp;
            }
            else {
                pTemp2->next = pTemp->next;
                pTemp->next->prev = pTemp2;
                pTemp->next = pTemp2;
                pTemp2->prev = pTemp;
            }

            //check if we need to insert the new val to the first half or the second half of the node
            int t = i - pTemp->getHalfNodeSize();

            // If we insert val to the second half
            if (t>=0){
                int h = pTemp->getHalfNodeSize()-1;
                while (h>0){                        //move n - n/2 elements down (n is the max number of elements)
                    pTemp2->add(pTemp->elements[pTemp->numElements-h]);
                    pTemp->removeAt(pTemp->numElements-h);
                    h--;
                }
                pTemp2->insertAt(t,val);
            }

            // If we insert val to the first half
            else{
                int h = pTemp->getHalfNodeSize();
                while (h>0){                    //move n/2 elements down (n is the max number of elements)
                    pTemp2->add(pTemp->elements[pTemp->numElements-h]);
                    pTemp->removeAt(pTemp->numElements-h);
                    h--;
                }
                pTemp->insertAt(i,val);
            }
            this->numOfNodes++;
        }
        size1++;
	}
}

void UnrolledLinkedList::deleteAt(int pos)
{
	if (pos < 0 || pos >= size1)
		throw "IndexOutOfBoundsException";  // check whether pos is valid or not
	else if (this->size1 == 0){             // If the list is empty
        throw "The list is empty";
	}
	else if (this->size1 == 1){             // If there is only one element left
        this->head->removeAt(0);
        this->size1--;
        this->numOfNodes--;
        Node *pTemp = this->head;
        this->head = NULL;
        this->tail = NULL;
        delete(pTemp);
        return;
	}
	else{                                   // Other cases
        int m = pos+1;
        int n = 1, i;
        Node *getpos = this->head;
        while (getpos != NULL){
            for (i=0; i<getpos->numElements; i++){
                if (m == n){
                    goto theEnd;            //break when we reach the pos
                }
                n++;
            }
            getpos = getpos->next;
        }

        theEnd:
        getpos->removeAt(i);                // Delete the element first
        int s = getpos->getHalfNodeSize();  // Then check if that node's num of elements is less than its half size
        if (getpos->numElements < s && this->numOfNodes > 1){

            // If the node is in the middle (not a head or tail) & the prev node has more than a half num of elements
            if (getpos->prev != NULL && getpos->next != NULL && getpos->prev->numElements > s){
                getpos->insertAt(0, getpos->prev->elements[getpos->prev->numElements-1]);
                getpos->prev->removeAt(getpos->prev->numElements-1);
            }

            // If the node is in the middle (not a head or tail) & the next node has more than a half num of elements
            else if (getpos->prev != NULL && getpos->next != NULL && getpos->next->numElements > s){
                getpos->insertAt(getpos->numElements, getpos->next->elements[0]);
                getpos->next->removeAt(0);
            }

            // If the node is in the middle (not a head or tail) & we must combine it with its prev node
            else if (getpos->prev != NULL && getpos->next != NULL && getpos->prev->numElements == s){
                int s2 = getpos->numElements;
                for (int i=0; i<s2; i++){
                    getpos->prev->add(getpos->elements[0]);
                    getpos->removeAt(0);
                }
                Node *pTemp = getpos;
                getpos->prev->next = pTemp->next;
                getpos->next->prev = pTemp->prev;
                delete(pTemp);
                this->numOfNodes--;
            }

            // If the node is the tail & the rev node has more than a half num of elements
            else if (getpos->prev != NULL && getpos->next == NULL && getpos->prev->numElements > s){
                getpos->insertAt(0, getpos->prev->elements[getpos->prev->numElements-1]);
                getpos->prev->removeAt(getpos->prev->numElements-1);
            }

            // If the node is the tail & we must combine it with its prev node
            else if (getpos->prev != NULL && getpos->next == NULL && getpos->prev->numElements == s){
                int s2 = getpos->numElements;
                for (int i=0; i<s2; i++){
                    getpos->prev->add(getpos->elements[0]);
                    getpos->removeAt(0);
                }
                this->tail = getpos->prev;
                this->tail->next = NULL;
                delete(getpos);
                this->numOfNodes--;
            }

            // If the node is the head & the next node has more than a half num of elements
            else if (getpos->prev == NULL && getpos->next != NULL && getpos->next->numElements > s){
                getpos->insertAt(getpos->numElements, getpos->next->elements[0]);
                getpos->next->removeAt(0);
            }

            // If the node is the head & we must combine it with its next node
            else if (getpos->prev == NULL && getpos->next != NULL && getpos->next->numElements == s) {
                int s2 = getpos->next->numElements;
                for (int i=0; i<s2; i++){
                    getpos->add(getpos->next->elements[0]);
                    getpos->next->removeAt(0);
                }
                Node *pTemp = getpos->next;
                this->head = getpos;
                getpos->prev = NULL;
                getpos->next = pTemp->next;
                pTemp->next->prev = getpos;
                delete(pTemp);
                this->numOfNodes--;
            }

        }
        this->size1--;
    }
}

int UnrolledLinkedList::firstIndexOf(int val) {
    if (this->size1 == 0){                  // return -1 if the linked list is empty
        return -1;
    }
    else{                                   //check through each element of each Node until we reach our destination
        int n = 0;
        Node *pTemp = this->head;
        while (pTemp != NULL){
            for (int i=0; i<pTemp->numElements; i++){
                if (pTemp->elements[i] == val){
                    return n;
                }
                else {
                    n++;
                }
            }
            pTemp = pTemp->next;
        }
    }
    return -1;                              //return -1 if we go through all elements and cannot find the element has value val
}

int UnrolledLinkedList::lastIndexOf(int val) {
    if (this->size1 == 0){                  // return -1 if the linked list is empty
        return -1;
    }
    else{                                   //check through each element of each Node until we reach our destination
        int n = 0;
        int m = -1;
        Node *pTemp = this->head;
        while (pTemp != NULL){
            for (int i=0; i<pTemp->numElements; i++){
                if (pTemp->elements[i] == val){
                    m = n;
                }
                n++;
            }
            pTemp = pTemp->next;
        }
        return m;                       //return m: index of last element
                                        //or -1 if we go through all elements and cannot find the element has value val
    }
}

bool UnrolledLinkedList::contains(int val) {
    Node *pTemp;
    pTemp = this->head;
    if (this->size1 == 0){                              //if the list is empty, return false
        return false;
    }
    else{
        while (pTemp != NULL){                          //check each Node
            for(int i=0; i<pTemp->numElements; i++){    //check each element of a Node
                if (pTemp->elements[i] == val){
                    return true;
                }
            }
            pTemp = pTemp->next;
        }
    }
    return false;
}

void UnrolledLinkedList::reverse1() {
	if (this->numOfNodes == 0){                         //if list is empty, return
        return;
	}
	else if (this->numOfNodes == 1){                    //if there's only one node, reverse elements in that node
        Node *pTemp;
        pTemp = new Node(this->nodeSize);
        for (int i=this->head->numElements-1; i>=0; i--){
            pTemp->add(this->head->elements[i]);
        }
        Node *pTemp2 = this->head;
        this->head = pTemp;
        this->tail = pTemp;
        pTemp->next = NULL;
        delete(pTemp2);
	}
	else {                                              //if there are more than 1 node
        Node *pTemp;
        pTemp = this->head;
        this->head = this->tail;
        this->tail = pTemp;

        pTemp = this->head;
        do {                                            //run a loop to reverse Nodes first by swapping prev and next of each Node
            Node *pTemp2;
            pTemp2 = pTemp->next;
            pTemp->next = pTemp->prev;
            pTemp->prev = pTemp2;
            pTemp = pTemp->next;
        }
        while (pTemp != NULL);

        pTemp = this->head;
        Node *pTemp3;

        pTemp3 = new Node(this->nodeSize);              //reverse elements of the head
        for (int i=pTemp->numElements-1; i>=0; i--){
                pTemp3->add(pTemp->elements[i]);
        }
        pTemp3->prev = pTemp->prev;
        pTemp3->next = pTemp->next;
        this->head = pTemp3;
        pTemp->next->prev = pTemp3;

        Node *pTemp4 = pTemp;
        pTemp = pTemp3;
        delete(pTemp4);
        pTemp = pTemp->next;

        while (pTemp->next != NULL){                    //then run a loop to reverse elements in a node, except the head and the tail
            pTemp3 = new Node(this->nodeSize);
            for (int i=pTemp->numElements-1; i>=0; i--){
                pTemp3->add(pTemp->elements[i]);
            }
            pTemp3->prev = pTemp->prev;
            pTemp3->next = pTemp->next;
            pTemp->prev->next = pTemp3;
            pTemp->next->prev = pTemp3;

            Node *pTemp4 = pTemp;
            pTemp = pTemp3;
            delete(pTemp4);
            pTemp = pTemp->next;
        }
        pTemp3 = new Node(this->nodeSize);              //then reverse elements of the tail afterward
        for (int i=pTemp->numElements-1; i>=0; i--){
                pTemp3->add(pTemp->elements[i]);
        }
        pTemp3->prev = pTemp->prev;
        pTemp->prev->next = pTemp3;
        pTemp3->next = NULL;
        this->tail = pTemp3;
        pTemp4 = pTemp;
        delete(pTemp4);
	}
}

///////////////////////////////
///// Thank you Teacher! //////
///////////////////////////////

