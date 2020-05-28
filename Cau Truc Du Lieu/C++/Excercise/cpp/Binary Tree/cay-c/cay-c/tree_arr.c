#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 50
#define NIL -1
typedef char DataType;
typedef int Node;
typedef struct {
   DataType Data[MAXLENGTH];  
   Node Parent[MAXLENGTH];
   int MaxNode; 
} Tree; 

void MakeNull_Tree (Tree *T) {
	(*T).MaxNode=0; 
}

int EmptyTree(Tree T) {
    return T.MaxNode == 0;
}

Node Parent(Node n, Tree T) {
	if(EmptyTree(T)||(n>T.MaxNode-1))
     		return NIL;
	else return T.Parent[n];
} 


DataType Label_Node(Node n,Tree T) { 
	 if(!EmptyTree(T)&&(n<=T.MaxNode-1))
         return T.Data[n];
}

Node Root(Tree T) {
  if (!EmptyTree(T)) return 0;
  else return NIL;
}

Node LeftMostChild(Node n, Tree T) {
   Node i; int found;
   if (n<0) return NIL;
   i=n+1; found=0;
   while ((i<=T.MaxNode-1) && !found) 
          if (T.Parent[i]==n) found=1; 
          else i=i+1;
   if (found) return i;
   else return NIL;
}  
	   
Node RightSibling(Node n,Tree T) {
      Node i,parent;  int found;
	  if (n<0) return NIL;
	  parent=T.Parent[n];
	  i=n+1; found=0;
      while ((i<=T.MaxNode-1) && !found)
           if (T.Parent[i]==parent) found=1;
           else i=i+1;
      if (found) return i; 
      else return NIL;
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


void PostOrder(Node n,Tree T) {
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
	int i,N;
	DataType X;
	Node node;
	MakeNull_Tree(T);
	printf("So nut cua cay N= ");
	scanf("%d",&N);getchar();
	T->MaxNode = N;
	printf("Nhap nhan\n");
	for(i=1;i<=N;i++) { 
		printf("Nhan nut thu %d: ",i);
		scanf("%c",&X);
		getchar();
		T->Data[i-1] = X;
	}
	printf("Nhap chi so nut cha\n");
	for(i=1;i<=N;i++) { 
		printf("Cha cua nut thu %d: ",i);
		scanf("%d",&node);
		T->Parent[i-1] = node;
	}	
}

int L_count(Node n, Tree T) {
	if(n == NIL)
		return 0;
	else {
		int i = LeftMostChild(n, T);
		if(i == NIL)
			return 1;
		else {
			int count = 0;
			while(i != NIL) {
				count = count + L_count(i, T);
				i = RightSibling(i, T);
			}
			return count;
		}
	}	
}


main() {
	Tree T;
	
	ReadTree(&T);
	
	printf("\n Duyet tien tu: ");
	PreOrder(0, T);
	
	printf("\n Duyet trung tu: ");
	InOrder(0, T); 

	printf("\n Duyet hau tu: ");
	PostOrder(0, T);

	printf("\n Tong so nut la: %d \n", L_count(0, T));
	
	return 0;
} 
