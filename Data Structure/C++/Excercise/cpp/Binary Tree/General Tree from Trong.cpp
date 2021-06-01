#include<stdio.h>

#define MAXLENGTH 104
#define NULL -1
typedef int DataType;
typedef int Node;
typedef struct {

DataType Data[MAXLENGTH]; 

Node Parent[MAXLENGTH]; 

int MaxNode; 
} Tree; 
 Tree T;


void MAKENULL_TREE (Tree& T){
 	T.MaxNode=0;
}


int EMPTY_TREE(Tree T){
 	return T.MaxNode == 0;
}

Node PARENT(Node n,Tree T){
	if (EMPTY_TREE(T) || (n>T.MaxNode-1))
   		return NULL;
	else return T.Parent[n];
}

DataType LABEL_NODE(Node n,Tree T){
	if (!EMPTY_TREE(T) && (n<=T.MaxNode-1))
	return T.Data[n];
}

Node ROOT(Tree T){
	if (!EMPTY_TREE(T)) return 0;
	else return NULL;
}

Node LEFTMOST_CHILD(Node n,Tree T){
Node i;
	if (n<0) return NULL;
		i=n+1;
	while (i<=T.MaxNode-1) 
		if (T.Parent[i]==n) return i;
		else i=i+1;
	return NULL;
}

Node RIGHT_SIBLING(Node n,Tree T){
	Node i,parent;
		if (n<0) return NULL;
			parent=T.Parent[n];
			i=n+1;
		while (i<=T.MaxNode-1) 
			if (T.Parent[i]==parent) return i; 
			else 
				i=i+1;
		return NULL;
}

void PreOrder(Node n,Tree T){
	if (n!=NULL){
		printf("%c ",LABEL_NODE(n,T));
	Node i=LEFTMOST_CHILD(n,T);
	while (i!=NULL){
		PreOrder(i,T);
 		i=RIGHT_SIBLING(i,T);
}
}
}

void InOrder(Node n,Tree T){
	Node i=LEFTMOST_CHILD(n,T);
	if (i!=NULL) 
		InOrder(i,T);
		printf("%c ",LABEL_NODE(n,T));
		i=RIGHT_SIBLING(i,T);
	while (i!=NULL){
  		InOrder(i,T);
  		i=RIGHT_SIBLING(i,T);
}
}
void PosOrder(Node n,Tree T){
	Node i=LEFTMOST_CHILD(n,T);
	while (i!=NULL){
 		PosOrder(i,T);
 		i=RIGHT_SIBLING(i,T);
}
		printf("%c ",LABEL_NODE(n,T));
}	 

void READTREE(Tree& T){
	int i;
	MAKENULL_TREE(T);
	do {
		printf("Cay co bao nhieu nut?");
		scanf("%d",&T.MaxNode);
} 	while ((T.MaxNode<1) || (T.MaxNode>MAXLENGTH));
		printf("Nhap nhan cua nut goc ");
		fflush(stdin);
		scanf("%c",&T.Data[0]);
		T.Parent[0]=NULL; /* nut goc khong co cha */
		for (i=1;i<=T.MaxNode-1;i++){
			printf("Nhap cha cua nut %d ",i);
			scanf("%d",&T.Parent[i]);
			printf("Nhap nhan cua nut %d ",i);
			fflush(stdin);
			scanf("%c",&T.Data[i]);
		}
}

int main(){
	
	printf("Nhap du lieu cho cay tong quat\n");
	READTREE(T);
	printf("Danh sach duyet tien tu cua cay vua nhap la\n");
	PreOrder(ROOT(T),T); 
	printf("\nDanh sach duyet trung tu cua cay vua nhap la\n");
	InOrder(ROOT(T),T);
	printf("\nDanh sach duyet hau tu cua cay vua nhap la\n");
	PosOrder(ROOT(T),T);
	
	return 0;
}

