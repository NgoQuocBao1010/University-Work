
#include <stdio.h>
#include <conio.h>


#define MaxSize 100

#define MINVALUE -32768 

typedef int KeyType;
typedef struct{
   KeyType Keys[MaxSize];
   int size;

}PriorityQueue;


int getParent(int index){
	return index / 2;	
}


int leftChild(int index){
	return 2 * index;
}

int rightChild(int index){
	return 2 * index + 1;
}


int size(PriorityQueue *q){
	return (*q).size;
}


bool isEmpty(PriorityQueue *q){
	return (*q).size == 0;
}


void clear(PriorityQueue *q){
	int i=0;
	
	for (i=0; i <= (*q).size - 1; i++){
		(*q).Keys[i] = 0;
	}
	
	(*q).size = 0;
}


KeyType peek(PriorityQueue *q){
	if (isEmpty(q)) return 0;
	
	return (*q).Keys[0];
}


KeyType poll(PriorityQueue *q){
	if (isEmpty(q)) return 0;
	int root;
	root = (*q).Keys[0];
	return 0;
}


void increaseKey(PriorityQueue *q, int index, KeyType k){
	if (k < (*q).Keys[index]){
		return;
	}
	
	int parent;
	parent = index / 2;
	
	(*q).Keys[index] = k;
	
	
	while (index > 0 && (*q).Keys[parent] < (*q).Keys[index]){
//		printf("%d \t %d", &(*q).Keys[parent], &(*q).Keys[index]);
		(*q).Keys[parent] = (*q).Keys[index];
		index = index / 2;
	}
}


int main(){
	int i,j;
	KeyType k;
	PriorityQueue Q = {{16, 14, 10, 8, 7, 9, 3, 2, 4, 1}, 10};
	i=9;
	k=15;
	increaseKey(&Q,i,k);
	for(j=0; j<=Q.size-1; j++)
		printf("%d ",Q.Keys[j]);
	printf("\n%d ",Q.size);
	return 0;
}






