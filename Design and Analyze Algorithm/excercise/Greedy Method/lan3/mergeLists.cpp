#include <iostream>
using namespace std;

#define oo 1000000000
#define N 1000
#define MaxSize 100007


// =================================== Priority Queue ===================================
// ===================================    Min Heap    ===================================
typedef long long KeyType;
typedef struct {
    KeyType key;
    long long value;
} KeyValuePair;

typedef struct{
    KeyValuePair *key;
    long long size;
} PriorityQueue;

void makeNull(PriorityQueue &pq);
bool isEmpty(PriorityQueue pq);
void swapElement(PriorityQueue &pq ,long long pos1, long long pos2);
void sink(PriorityQueue &pq, long long i);
void build_MinHeap(PriorityQueue &pq);
KeyValuePair poll(PriorityQueue &pq);
void swim(PriorityQueue &pq, long long position);
void insertElement(PriorityQueue &pq, KeyType key, long long value);


// ===================================  Bai 3   ===================================

void mergeLists(){
    long long numOfLists;
    cin >> numOfLists;

    PriorityQueue q;
    makeNull(q);

    long long operators = 0;

    for (long long i=0; i<numOfLists; i++){
        long long sizeOfList;
        cin >> sizeOfList;

        if (numOfLists == 1) {
            cout << sizeOfList << endl;
            return;
        }
        insertElement(q, sizeOfList, sizeOfList);
    }

    while (true){
        KeyValuePair size1 = poll(q);
        KeyValuePair size2 = poll(q);

        long long newSize = size1.key + size2.key;
        operators += newSize;

        if (isEmpty(q)) break;

        // cout << size1.key << " " << size2.key << " " << operators << endl;
        
        insertElement(q, newSize, newSize);
    }
    cout << operators << endl;
}


int main(){
    // freopen("merge05.inp", "r", stdin);
    mergeLists();
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
void swapElement(PriorityQueue &pq ,long long pos1, long long pos2){
    KeyValuePair ele1 = pq.key[pos1];
    KeyValuePair ele2 = pq.key[pos2];

    pq.key[pos1] = ele2;
    pq.key[pos2] = ele1;
}

// Also known as min_Heapify
// sink down an element if that element
// does not satifies heap's variant
void sink(PriorityQueue &pq, long long position){
    while (true) {
        long long leftPos = 2 * position + 1;
        long long rightPos = 2 * position + 2;
        long long smallest = leftPos;

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
    for (long long i=pq.size/2 - 1; i>=0; i--){
        sink(pq, i);
    }
}

// Also know as extractMin
KeyValuePair poll(PriorityQueue &pq){
    KeyValuePair min = pq.key[0];
    // pq.size --;
    swapElement(pq, 0, pq.size - 1);
    pq.size --;
    sink(pq, 0);
    return min;
}

// Also known as decreaseKey
// Swim up an element to satisfy the heap's variant
void swim(PriorityQueue &pq, long long position){
    long long parentPos = (position - 1) / 2;

    while (position > 0 && pq.key[parentPos].value > pq.key[position].value){
        swapElement(pq, parentPos, position);
        position = parentPos;
        parentPos = (position - 1) / 2;
    }
}


void insertElement(PriorityQueue &pq, KeyType key, long long value){
    KeyValuePair newElement = {key, value};
    pq.key[pq.size] = newElement;
    swim(pq, pq.size);
    pq.size++;
}







