#include <stdio.h>

#define MAXLENGTH 50
#define NIL -1

typedef  char DataType;
typedef int Node;

typedef struct {
   DataType Data[MAXLENGTH];  
   Node Parent[MAXLENGTH]; 
   int MaxNode;
} Tree; 
Tree T; 

void MakeNull_Tree (Tree *T) {
	(*T).MaxNode=0; 
}

int EmptyTree(Tree T) {
    return T.MaxNode == 0;
}

Node Parent(Node n, Tree T) {
	if(EmptyTree(T)||(n>T.MaxNode-1))
     	return NIL;
	else 
		return T.Parent[n];
} 

DataType Label_Node(Node n,Tree T) { 
	if(!EmptyTree(T)&&(n<=T.MaxNode-1))
        return T.Data[n];
}

Node Root(Tree T) {
	if (!EmptyTree(T)) 
		return 0;
	else 
		return NIL;
} 

Node LeftMostChild(Node n, Tree T) {
	Node i; 
	int found;
	if (n<0) 
		return NIL;
	i=n+1; found=0;
	while ((i<=T.MaxNode-1) && !found) 
        if (T.Parent[i]==n) 
			found=1; 
        else 
			i=i+1;
			
	if (found) 
		return i;
	else 
		return NIL;
} 

Node RightSibling(Node n,Tree T) {
    Node i,parent;  
	int found;
	if (n<0) 
		return NIL;
		
	parent=T.Parent[n];
	i=n+1; found=0;
    while ((i<=T.MaxNode-1) && !found)
        if (T.Parent[i]==parent) 
			found=1;
        else 
			i=i+1;
			
    if (found) 
		return i; 
    else 
		return NIL;
 } 
 
void PreOrder(Node n,Tree T) {
	if (n != NIL) {
		Node i;
		printf("%c ", Label_Node(n,T));
		i=LeftMostChild(n,T);
		while (i!=NIL) {
			PreOrder(i,T);
			i=RightSibling(i,T);
		}
	}
} 

void InOrder(Node n, Tree T) {
	if (n!= NIL) {
		Node i;
		i=LeftMostChild(n, T);
		if (i!=NIL) InOrder(i,T);
		printf("%c ",Label_Node(n,T));
		i=RightSibling(i,T);
		while (i!=NIL) {
			InOrder(i,T);
			i=RightSibling(i,T);
		}
	}
} 

void PostOrder(Node n, Tree T) {
	if (n!=NIL) {
		Node i;
		i=LeftMostChild(n,T);
		while (i!=NIL) {
			PostOrder(i,T);
			i=RightSibling(i,T);
		}
		printf("%c ",Label_Node(n,T));
	}
}

void ReadTree(Tree *T) {
	int i, n;
	char label;
	int	parent;
	
	MakeNull_Tree(T);
	printf("So nut trong cay? "); 
	scanf("%d",&n); 
	T->MaxNode = n;
	for(i = 0; i< n; i++) {
		getchar();
		printf("Nhan nut thu %d: ", i); 
		scanf("%c",&label);
		T->Data[i] = label;
		printf("Nhan chi so cha cua nut thu %d: ", i); 
		scanf("%d",&parent);
		T->Parent[i] = parent;
	}
}

main() {
	Tree T;
	ReadTree(&T);
	
	printf("\nDuyet tien tu\n");
	PreOrder(0, T);
	
	printf("\nDuyet trung tu\n");
	InOrder(0, T);
	
	printf("\nDuyet hau tu\n");
	PostOrder(0, T);		
}


