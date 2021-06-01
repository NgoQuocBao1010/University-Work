#include <stdio.h>
#include <stdlib.h>

typedef char TData;
typedef struct TNode* TNodeType; 
struct TNode {
		TData data;
    	TNodeType left,right;
};
typedef TNodeType TTree;

void MakeNullTree(TTree *T) { 
	(*T)=NULL; 
}

int EmptyTree(TTree T) {
	return T==NULL;
} 

TTree LeftChild(TTree n) {
	if (n!=NULL) return n->left;
	else return NULL; 
} 

TTree RightChild(TTree n) {
 	if (n!=NULL) return n->right;
 	else return NULL;
}

int IsLeaf(TTree n) {
    if(n!=NULL)
		return(LeftChild(n)==NULL)&&(RightChild(n)==NULL);
	else 
		return -1;
} 

void PreOrder(TTree T) {
  if (T!= NULL) {
  	printf("%c ",T->data);  
   	PreOrder(LeftChild(T));
    PreOrder(RightChild(T));
  }
}

void InOrder(TTree T) {
  if (T!= NULL) {
   	InOrder(LeftChild(T));
  	printf("%c ",T->data);  
    InOrder(RightChild(T));
  }
}

void PostOrder(TTree T) {
  if (T!= NULL) {
   	PostOrder(LeftChild(T));
    PostOrder(RightChild(T));
  	printf("%c ",T->data);  
  }
}

TTree Create2(TData v, TTree l, TTree r) {
	TTree N;
	N=(TNodeType)malloc(sizeof(struct TNode));
	N->data=v;
	N->left=l;
	N->right=r;
	return N; 
}

void CreateTree(TTree *T) {
/*****

           A
          /  \
		 B    C
        / \  / \  
       D  E F   G 
           / \   \ 
          I   J   K 			  
******/

(*T) = Create2('A',
			Create2('B', 
				Create2('D',NULL, NULL), 
				Create2('E',NULL, NULL)
			),
			Create2('C',
				Create2('F', 
					Create2('I', NULL, NULL),
					Create2('J', NULL, NULL)
				),
				Create2('G', 
					NULL,
					Create2('K', NULL, NULL)
				)
			)		
		);
		
}


int L_count(TTree T) {
	if(EmptyTree(T)) return 0;
	if(IsLeaf(T)) return 1;
	else
		return L_count(T->left) + L_count(T->right);
}

int N_count(TTree T) {
	if (EmptyTree(T)) return 0;
	else
		return 1 + N_count(T->left) + N_count(T->right);
}

int max(int a, int b) {
	return (a>b)?a:b;
}

int h(TTree T) {
	if (EmptyTree(T)) return 0;
	if (IsLeaf(T)) return 0;
	else
		return 1 + max(h(T->left), h(T->right));
}

int Exist(TData v, TTree T) {
	if(EmptyTree(T)) return 0;
	if(T->data == v)
		return 1;
	else 
		return Exist(v, T->left) + Exist(v, T->right);
}

TTree Ref(TData v, TTree T) {
	if(EmptyTree(T)) return NULL;
	if(T->data == v)
		return T;
	else {
		TTree p = Ref(v, T->left);
		if(p != NULL) return p;
		else return Ref(v, T->right);
	}	
}

int Des(TData u, TData v, TTree T) {
	return Exist(v, Ref(u, T));
}

TData Parent(TData v, TTree T) {
	if (EmptyTree(T)) return -1;
	if (IsLeaf(T)) return -1;
	else {
		TData p;
		if(T->left != NULL)
			if(T->left->data == v)
				p = T->data;
			else
				p = Parent(v, T->left);
		if ((p == -1) && (T->right != NULL)) 
			if(T->right->data == v)
				p = T->data;
			else
				p = Parent(v, T->right);
		return p;
	}
}

main() {
	TTree T;
	CreateTree(&T);
	
	printf("\n Duyet tien tu: ");
	PreOrder(T);
	
	printf("\n Duyet trung tu: ");
	InOrder(T); 

	printf("\n Duyet hau tu: ");
	PostOrder(T);
	
	printf("\n Tong so nut cua cay: %d \n", N_count(T));
	
	printf("\n Tong so nut la: %d \n", L_count(T));
	
	printf("\n Chieu cao cay: %d \n", h(T));

	if(Exist('C', T))
		printf("\n Nhan C co trong Cay\n");
	else 	
		printf("\n Nhan C khong co trong Cay\n");	

	if(Exist('Q', T))
		printf("\n Nhan Q co trong Cay\n");
	else 	
		printf("\n Nhan Q khong co trong Cay\n");	

	if(Des('A', 'G', T))
		printf("\n G la hau due cua A\n");
	else 	
		printf("\n G khong la hau due cua A\n");	

	if(Des('B', 'K', T))
		printf("\n K la hau due cua B\n");
	else 	
		printf("\n K khong la hau due cua B\n");	

	printf("\n Cha cua F la %c \n", Parent('F', T));
	
	printf("\n Cha cua M la %c \n", Parent('M', T));	

	return 0;
} 
