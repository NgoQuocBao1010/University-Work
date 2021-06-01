#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
typedef struct Node* NodeType;
struct Node{
	DataType Data;
	NodeType left, right;
};

typedef NodeType Tree;

void MakeNull(Tree *n){
	(*n) = NULL;
}

Tree LeftChild(Tree n){
	if ( n != NULL) return n->left;
	else return NULL;
}

Tree RightChild(Tree n){
	if (n != NULL) return n->right;
	else return NULL;
}


void PreOrder(Tree t){
	if (t != NULL) {
		printf("%c ", t->Data);
		PreOrder(LeftChild(t));
		PreOrder(RightChild(t));
	}
}

void InOrder(Tree t){
	if (t != NULL) {
		InOrder(LeftChild(t));
		printf("%c ", t->Data);
		InOrder(RightChild(t));
	}
}

void PostOrder(Tree t){
	if (t != NULL) {
		PostOrder(LeftChild(t));
		PostOrder(RightChild(t));
		printf("%c ", t->Data);
	}
}

Tree Create2(DataType v, Tree l, Tree r){
	Tree n;
	n = (NodeType)malloc(sizeof(struct Node));
	n->Data = v;
	n->left = l;
	n->right = r;
	return n;
}

int main(){
	Tree T;
	MakeNull(&T);
	(T) = Create2('A',
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
		
	
	printf("\n Duyet tien tu: ");
	PreOrder(T);
	
	printf("\n Duyet trung tu: ");
	InOrder(T); 

	printf("\n Duyet hau tu: ");
	PostOrder(T);

	return 0;
}
/*****

            A
          /  \
		 B    C
        / \  / \  
       D  E F   G 
           / \   \ 
          I   J   K 			  
******/

