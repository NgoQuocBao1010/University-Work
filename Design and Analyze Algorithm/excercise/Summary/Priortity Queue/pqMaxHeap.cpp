#include <iostream>
using namespace std;

#define oo 1000000000
#define N 1000
#define MaxSize 100007


// =================================== Priority Queue ===================================
// ===================================    MAx Heap    ===================================
typedef int KeyType;
typedef struct {
    KeyType key;
    int value;
} KeyValuePair;

typedef struct{
    KeyValuePair *key;
    int size;
} PriorityQueue;

void makeNull(PriorityQueue &pq);
bool isEmpty(PriorityQueue pq);
void swapElement(PriorityQueue &pq ,int pos1, int pos2);
void sink(PriorityQueue &pq, int i);
void build_MaxHeap(PriorityQueue &pq);
KeyValuePair poll(PriorityQueue &pq);
void swim(PriorityQueue &pq, int position);
void insertElement(PriorityQueue &pq, KeyType key, int value);



int main(){
    PriorityQueue q;
    makeNull(q);
    
    for (int i=0; i<22; i++)
        insertElement(q, i, i);

    cout << poll(q).key << endl;
    cout << poll(q).key << endl;
    cout << poll(q).key << endl;
    cout << poll(q).key << endl;

    for (int i=40; i<60; i++)
        insertElement(q, i, i);
    
    cout << poll(q).key << endl;
    cout << poll(q).key << endl;
    cout << poll(q).key << endl;
    cout << poll(q).key << endl;
}

// ===================================    Queue Method    ===================================
void makeNull(PriorityQueue &q){
    q.size = 0;
    q.key = new KeyValuePair[MaxSize];
}


bool isEmpty(PriorityQueue pq){
    return pq.size == 0;
}

// swap to element in the queue by passing their positions
void swapElement(PriorityQueue &pq ,int pos1, int pos2){
    KeyValuePair ele1 = pq.key[pos1];
    KeyValuePair ele2 = pq.key[pos2];

    pq.key[pos1] = ele2;
    pq.key[pos2] = ele1;
}

// Also known as max_heapify
// sink down an element if that element
// does not satifies heap's variant
void sink(PriorityQueue &pq, int position){
    while (true) {
        int leftPos = 2 * position + 1;
        int rightPos = 2 * position + 2;
        int biggest = leftPos;

        if (rightPos < pq.size && pq.key[rightPos].value > pq.key[leftPos].value)
            biggest = rightPos;
        
        if (leftPos >= pq.size || pq.key[position].value > pq.key[biggest].value)
            break;
        
        swapElement(pq, biggest, position);
        position = biggest;
    }
}

// a faster way build a min heap
void build_MaxHeap(PriorityQueue &pq){
    for (int i=pq.size/2 - 1; i>=0; i--){
        sink(pq, i);
    }
}

// Also know as extractMin
KeyValuePair poll(PriorityQueue &pq){
    KeyValuePair max = pq.key[0];
    pq.size --;
    swapElement(pq, 0, pq.size);
    sink(pq, 0);
    return max;
}

// Also known as decreaseKey
// Swim up an element to satisfy the heap's variant
void swim(PriorityQueue &pq, int position){
    int parentPos = (position - 1) / 2;

    while (position > 0 && pq.key[parentPos].value < pq.key[position].value){
        swapElement(pq, parentPos, position);
        position = parentPos;
        parentPos = (position - 1) / 2;
    }
}


void insertElement(PriorityQueue &pq, KeyType key, int value){
    KeyValuePair newElement = {key, value};
    pq.key[pq.size] = newElement;
    swim(pq, pq.size);
    pq.size++;
}







