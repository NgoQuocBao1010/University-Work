#include <stdio.h>
#include <stdlib.h>

#define oo 1000000000
#define N 1000
#define MaxSize 100007

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

void whatTheFrickIsThisEx(){
    long long sizeOfArr;
    scanf("%lld", &sizeOfArr);

    long long* result = (long long*) malloc(sizeOfArr * sizeof(long long));

    PriorityQueue q;
    makeNull(&q);
    long long multiplyResult = 1;
    for (long long i=0; i<sizeOfArr; i++){
        long long element;
        scanf("%lld", &element);
        insertElement(&q, element, element);
        multiplyResult *= element;
        if (i < 2){
            result[i] = -1;
            continue;
        }
        
        if (i > 2){
            long long minEle = extractMin(&q).key;
            min_Heapify(&q, 0);

            multiplyResult = multiplyResult / minEle;
        }
        result[i] = multiplyResult;
    }

    for (long long i=0; i<sizeOfArr; i++){
        printf("%lld\n", result[i]);
    }
}

int main(){
    whatTheFrickIsThisEx();
    // PriorityQueue q;
    // makeNull(&q);
    // insertElement(&q, 1, 1);
    // insertElement(&q, 2, 2);
    // insertElement(&q, 3, 3);
    // // swapElement(&q, 0, 1);
    // extractMin(&q);
    // insertElement(&q, 4, 4);
    // extractMin(&q);
    // insertElement(&q, 5, 5);
    // printf("fadsfadsf %lld %lld %lld\n", q.key[0].key, q.key[1].key, q.key[2].key);
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
