#include <stdio.h>

#define MaxSize 100

#define MINVALUE -32768 

typedef int KeyType;
typedef struct{
   KeyType Keys[MaxSize];
   int size;

}PriorityQueue;


bool isEmpty(PriorityQueue *q){
	return (*q).size == 0;
}


int parent(int index){
	index ++;
	return index / 2 - 1;
}


int right(PriorityQueue q, int index){
	int rightNode;
	rightNode = (2 * index + 2);
	
	if (rightNode >= q.size) return -1;
	
	return rightNode;
}


int left(PriorityQueue q, int index){
	int leftNode;
	leftNode = (2 * index + 1);
	
	if (leftNode >= q.size) return -1;
	
	return leftNode;
}


void increaseKey(PriorityQueue *q, int index, KeyType k){
	if (k < (*q).Keys[index]){
		return;
	}
	int p_node, temp;
	p_node = parent(index);
	
	(*q).Keys[index] = k;
	
	while (index > 0 && (*q).Keys[p_node] < (*q).Keys[index]){
		temp = (*q).Keys[p_node];
		(*q).Keys[p_node] = (*q).Keys[index];
		(*q).Keys[index] = temp;
		
		index = p_node;
		p_node = parent(p_node);
	}
}


void insert(PriorityQueue *q, KeyType k){
	(*q).Keys[(*q).size] = k;
	(*q).size ++;
	
	int lastNode;
	lastNode = (*q).size - 1;
	
	increaseKey(q, lastNode, k);
}


void maxHeapify(PriorityQueue *q, int index){
	int l, r, largest, temp;
	l = 2 * index + 1;
	r = 2 * index + 2;
	largest = index;
	
	if (l < (*q).size && (*q).Keys[l] > (*q).Keys[largest]){
		largest = l;
	}
	
	if (r < (*q).size && (*q).Keys[r] > (*q).Keys[largest]){
		largest = r;
	}
//	printf("%d \n", (*q).Keys[largest]);
	if (largest != index){
		temp = (*q).Keys[index];
		(*q).Keys[index] = (*q).Keys[largest];
		(*q).Keys[largest] = temp;
		
		maxHeapify(q, largest);
	}
	
//	for(i=0; i<=(*q).size-1; i++)
//		printf("%d ",(*q).Keys[i]);
//	printf("%d \t %d \t %d",(*q).Keys[index], (*q).Keys[l], (*q).Keys[r]);/
//	printf("\n");
}


void buildMaxHeap(PriorityQueue *q){
	int i, n;
	n = (*q).size;
	for (i= (n/2) - 1; i>=0;i--){
	    maxHeapify(q, i);
	}
//	for(i=0; i<=(*q).size-1; i++)
//		printf("%d ",(*q).Keys[i]);
//	
//	printf("\n");
//16 14 10 8 7 9 3 2 4 1
}


int main(){
	int i;
	PriorityQueue Q = {{4, 1, 3, 2, 16, 9, 10, 14, 8, 7}, 10};
	buildMaxHeap(&Q);
	for(i=0; i<=Q.size-1; i++)
		printf("%d ",Q.Keys[i]);

}
