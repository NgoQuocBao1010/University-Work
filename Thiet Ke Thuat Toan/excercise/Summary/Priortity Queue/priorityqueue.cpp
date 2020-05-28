#include <iostream>
using namespace std;

#define oo 1000000000
#define N 1000
#define MaxSize 100007


// =================================== Priority Queue ===================================
// ===================================    Min Heap    ===================================
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
void build_MinHeap(PriorityQueue &pq);
KeyValuePair poll(PriorityQueue &pq);
void swim(PriorityQueue &pq, int position);
void insertElement(PriorityQueue &pq, KeyType key, int value);



int main(){
    PriorityQueue q;
    makeNull(q);
    
    for (int i=0; i<20; i++)
        insertElement(q, i, i);

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

// Also known as min_Heapify
// sink down an element if that element
// does not satifies heap's variant
void sink(PriorityQueue &pq, int position){
    while (true) {
        int leftPos = 2 * position + 1;
        int rightPos = 2 * position + 2;
        int smallest = leftPos;

        if (rightPos < pq.size && pq.key[rightPos].value < pq.key[leftPos].value)
            smallest = rightPos;
        
        if (leftPos >= pq.size || pq.key[position].value < pq.key[smallest].value)
            break;
        
        swapElement(pq, smallest, position);
        position = smallest;
    }
}

// a faster way build a min heap
void build_MinHeap(PriorityQueue &pq){
    for (int i=pq.size/2 - 1; i>=0; i--){
        sink(pq, i);
    }
}

// Also know as extractMin
KeyValuePair poll(PriorityQueue &pq){
    KeyValuePair min = pq.key[0];
    pq.size --;
    swapElement(pq, 0, pq.size);
    sink(pq, 0);
    return min;
}

// Also known as decreaseKey
// Swim up an element to satisfy the heap's variant
void swim(PriorityQueue &pq, int position){
    int parentPos = (position - 1) / 2;

    while (position > 0 && pq.key[parentPos].value > pq.key[position].value){
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







