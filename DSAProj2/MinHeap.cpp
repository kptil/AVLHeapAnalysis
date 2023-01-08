#include "MinHeap.h"
#include <iostream>

/*===== Insertion =====*/
void MinHeap::insert(int value) {
    theHeap.push_back(value);
    heapifyUp();
    numElements++;
}

void MinHeap::heapifyUp() {
    int child = theHeap.size() - 1;
    int parent = (child - 1) / 2;
    while (parent >= 0 && theHeap[parent] > theHeap[child]) {
        int temp = theHeap[parent];
        theHeap[parent] = theHeap[child];
        theHeap[child] = temp;
        child = parent;
        parent = (child - 1) / 2;
    }
}

/*===== Removal ======*/

//swap the root and the last element, delete last element, heapifyDown
void MinHeap::remove() {
	theHeap[0] = theHeap[theHeap.size() - 1];
	theHeap.pop_back();
	heapifyDown();
    numElements--;
}

void MinHeap::heapifyDown() {
	int size = theHeap.size();
    int p = 0;
    while (2 * p + 1 < size) {
        //cases: (i) 1 child (ia) parent larger, swap (ib) child larger, done
        //       (ii) 2 children (iia) parent larger than one, swap, (iib) parent larger than both, find min
        //       and swap (iic) parent smaller than both, done
        if (2 * p + 2 < size) {
            if ((theHeap[p] > theHeap[2 * p + 1]) || (theHeap[p] > theHeap[2 * p + 2])) {
                if (theHeap[2 * p + 2] < theHeap[2 * p + 1]) {
                    int temp = theHeap[p];
                    theHeap[p] = theHeap[2 * p + 2];
                    theHeap[2 * p + 2] = temp;
                    p = 2 * p + 2;
                }
                else {
                    int temp = theHeap[p];
                    theHeap[p] = theHeap[2 * p + 1];
                    theHeap[2 * p + 1] = temp;
                    p = 2 * p + 1;
                }
            }
            else { p = size; }
        }
        else {
            if (theHeap[p] > theHeap[2 * p + 1]) {
                int temp = theHeap[p];
                theHeap[p] = theHeap[2 * p + 1];
                theHeap[2 * p + 1] = temp;
                p = 2 * p + 1;
            }
            else { p = size; }
        }
    }
}

/*===== Traversal and Test Printing ======*/
void MinHeap::traverse() {
    int numElements = 0;
    for (int i = 0; i < theHeap.size(); i++) {
        cout << theHeap[i] << " ";
    }
    cout << endl;
}

void MinHeap::print() {
    for (int i = 0; i < theHeap.size(); i++) {
        cout << theHeap[i] << " ";
    }
    cout << endl;
}

int MinHeap::GetSize() {
    return numElements;
}