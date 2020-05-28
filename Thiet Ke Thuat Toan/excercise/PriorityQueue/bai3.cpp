#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100007
#define oo 1000000000000

typedef long long KeyType;
typedef struct {
    KeyType key;
    long long value;
} KeyValuePair;

typedef struct{
    KeyValuePair *key;
    long long size;
} PriorityQueue;

void makeNull(PriorityQueue *pq);
int isEmpty(PriorityQueue pq);
void swapElement(PriorityQueue *pq ,long long pos1, long long pos2);
void min_Heapify(PriorityQueue *pq, long long position);
void build_MinHeap(PriorityQueue *pq);
KeyValuePair extractMin(PriorityQueue *pq);
void decrease_Key(PriorityQueue *pq, long long position, KeyValuePair key);
void insertElement(PriorityQueue *pq, KeyType key, long long value);


void realMadrid(){
    long long numOfRows, numOfFans;
    scanf("%lld %lld", &numOfRows, &numOfFans);

    PriorityQueue q;
    makeNull(&q);

    for (int i=0; i<numOfRows; i++){
        long long numOfEmptyChairs;
        scanf("%lld", &numOfEmptyChairs);
        insertElement(&q, -numOfEmptyChairs, -numOfEmptyChairs);
    }

    long long sum, moneyForChair;
    sum = 0;
    for (int i=0; i<numOfFans; i++){
        moneyForChair = -extractMin(&q).key;
        min_Heapify(&q, 0);
        sum += moneyForChair;
        moneyForChair -= 1;
        insertElement(&q, -moneyForChair, -moneyForChair);
    }
    printf("%lld\n", sum);
}

int main(){
    realMadrid();
}

void makeNull(PriorityQueue *pq){
    pq->size = 0;
    pq->key = (KeyValuePair*) malloc(MaxSize*sizeof(KeyValuePair));
}

int isEmpty(PriorityQueue pq){
    return pq.size == 0;
}

void swapElement(PriorityQueue *pq ,long long pos1, long long pos2){
    KeyValuePair ele1 = pq->key[pos1];
    KeyValuePair ele2 = pq->key[pos2];

    pq->key[pos1].key = ele2.key;
    pq->key[pos1].value = ele2.value;
    pq->key[pos2].key = ele1.key;
    pq->key[pos2].value = ele1.value;
}

void min_Heapify(PriorityQueue *pq, long long position){
    long long smallest = position;
    long long leftPos = 2 * position + 1;
    long long rightPos = 2 * position + 2;

    if (leftPos < pq->size && pq->key[leftPos].value < pq->key[position].value)
        smallest = leftPos;
    
    if (rightPos < pq->size && pq->key[rightPos].value < pq->key[position].value)
        smallest = rightPos;
    
    if (smallest != position){
        swapElement(pq, smallest, position);
        min_Heapify(pq, smallest);
    }
}

void build_MinHeap(PriorityQueue *pq){
    for (long long i=pq->size/2 - 1; i>=0; i--){
        min_Heapify(pq, i);
    }
}

KeyValuePair extractMin(PriorityQueue *pq){
    KeyValuePair min = pq->key[0];
    pq->size --;
    swapElement(pq, 0, pq->size);
    min_Heapify(pq, 0);
    return min;
}

void decrease_Key(PriorityQueue *pq, long long position, KeyValuePair key){
    if (pq->key[position].value < key.value) return;

    pq->key[position] = key;
    long long parentPos = (position - 1) / 2;

    while (position > 0 && pq->key[parentPos].value > pq->key[position].value){
        swapElement(pq, parentPos, position);
        position = parentPos;
        parentPos = (position - 1) / 2;
    }
}

void insertElement(PriorityQueue *pq, KeyType key, long long value){
    KeyValuePair pair = {key, value};
    pq->key[pq->size].value = oo;
    pq->key[pq->size].key = key;
    pq->size++;
    decrease_Key(pq, pq->size - 1, pair);
}