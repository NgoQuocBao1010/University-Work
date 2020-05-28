#include <stdio.h>
#include <stdlib.h>

/* Khai bao kieu, bien */
typedef int KeyType;
typedef struct Node* NodeType; 
struct Node {	
	KeyType key;
	NodeType left,right;
};

typedef NodeType Tree;


/* Khoi tao cay rong */
void MakeNullTree(Tree *T) { 
	(*T)=NULL; 
}


/* Kiem tra cay co rong hay khong */
int EmptyTree(Tree T) {
	return T==NULL;
}


/* Them khoa x vao cay tree */
void InsertNode(KeyType x, Tree *Root) {
	if (*Root == NULL) {	
		(*Root)=(NodeType)malloc(sizeof(struct Node));
		(*Root)->key = x;
		(*Root)->left = NULL;
		(*Root)->right = NULL;
	}
 	else if (x < (*Root)->key) InsertNode(x, &((*Root)->left));
 	else if (x > (*Root)->key) InsertNode(x, &((*Root)->right));
} 


/* Tim khoa x cua cay tree */
Tree Search(KeyType x, Tree Root) {
	if (Root == NULL) 
		return NULL;
	else if (Root->key == x) 
		return Root;
	else if (Root->key < x)
        	return Search(x,Root->right);	
  	else
		return Search(x,Root->left);
 }


/* Xoa khoa nho nhat cua Root */
KeyType DeleteMin(Tree *Root) {
	KeyType k;
	if ((*Root)->left == NULL) {
		k=(*Root)->key;
		(*Root) = (*Root)->right;
		return k;
	} 
	else 
		DeleteMin(&((*Root)->left));
}


/* Xoa khoa x cua cay tree */
void DeleteNode(KeyType x, Tree *Root) {
	if ((*Root) != NULL)
		if (x < (*Root)->key)
 			DeleteNode(x, &((*Root)->left));
 		else if (x > (*Root)->key)
 			DeleteNode(x, &((*Root)->right));
		else if ((*Root)->left == NULL)
 			(*Root) = (*Root)->right;
 		else if ((*Root)->right == NULL)
 			(*Root) = (*Root)->left;
        else
			(*Root)->key = DeleteMin(&((*Root)->right));
}


/* Xoa khoa x cua cay tree ver. cua bai giang */
void DeleteNode1(KeyType x, Tree *Root) {
	if (*Root!=NULL)
		if(x < (*Root)->key) 
			DeleteNode(x, &((*Root)->left));
  		else if(x > (*Root)->key) 
			DeleteNode(x, &((*Root)->right));
		else if(((*Root)->left==NULL)&&((*Root)->right==NULL))
            		*Root=NULL;
  		else if((*Root)->left == NULL)
			(*Root) = (*Root)->right;
		else if((*Root)->right==NULL) 
			(*Root) = (*Root)->left;
  		else 
			(*Root)->key=DeleteMin(&((*Root)->right));
}


/* Tra ve con trai */
Tree LeftChild(Tree n)	{
	if (n!=NULL) 
		return n->left;
	else 
		return NULL; 
} 


/* Tra ve con phai */
Tree RightChild(Tree n)	{
	if (n!=NULL) 
		return n->right;
 	else 
		return NULL;
}


/* Kiem tra nut n co phai nut la hay khong */
int IsLeaf(Tree n) {
	if(n!=NULL)
		return(LeftChild(n)==NULL)&&(RightChild(n)==NULL);
	else 
		return NULL;
} 


/* Duyet tien to cay tree */
void PreOrder(Tree T) {
	if(T != NULL) {
		printf("%d ",T->key);
   		PreOrder(LeftChild(T));
   		PreOrder(RightChild(T));
	}	
}


/* Duyet trung to cay tree */
void InOrder(Tree T) {
	if(T != NULL) {
		InOrder(LeftChild(T));
		printf("%d ",T->key);
		InOrder(RightChild(T));
	}	
}


/* Duyet hau to cay tree */
void PostOrder(Tree T) {
	if (T!=NULL) { 
		PostOrder(LeftChild(T));
		PostOrder(RightChild(T));
		printf("%d ",T->key);
	}	
}


/* Tra ve tong so nut cua cay tree */
int nb_nodes(Tree T) {
  	if(EmptyTree(T)) 
		return 0;
    	else 
		return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
}


/* Tra ve tong so nut la cua cay tree */
int nb_leaves(Tree T) {
  	if(EmptyTree(T)) 
		return 0;
	else
		if(IsLeaf(T))
			return 1;
		else
			return nb_leaves(T->left) + nb_leaves(T->right);
} 


/* Tra ve chieu cao cua 1 nut */
int max(int x, int y) {
	int ret = (x>y)?x:y;
	return ret;
}

int h(Tree n) {
	if (IsLeaf(n) || (n == NULL))
		return 0;
	else
		return 1+max(h(n->left), h(n->right));
}


/* Tra ve do sau cua 1 nut n trong cay T */
int depth(Tree n, Tree T) {
	return h(T) - h(n);
}


/* Chtrinh chinh */
main() {
	Tree tree, node;
	KeyType x;
	int i, n;
	
	/* Tao cay rong */
	MakeNullTree(&tree);


	/* Nhap cac khoa */
	printf("Nhap vao bao nhieu so? "); scanf("%d", &n);
	for(i=0; i<n; i++) {
		printf("Nhap vao so thu %d: ",i+1); scanf("%d", &x);
		InsertNode(x, &tree);
	}

	/* Duyet cay */
	printf("\n duyet tien tu :"); PreOrder(tree);
	printf("\n duyet trung tu :"); InOrder(tree);
	printf("\n duyet hau tu :"); PostOrder(tree);

	/* Xoa khoa */
	printf("\n xoa khoa? "); scanf("%d", &x);
	DeleteNode1(x, &tree);
	/* Duyet cay */
	printf("\n duyet tien tu :"); PreOrder(tree);
	printf("\n duyet trung tu :"); InOrder(tree);
	printf("\n duyet hau tu :"); PostOrder(tree);

	/* Dem so nut va nut la cua cay */
	printf("\n so nut cua cay la %d \n", nb_nodes(tree));
	printf("\n so nut la cua cay la %d \n", nb_leaves(tree));

	/* Tim khoa */
	printf("\n tim khoa? "); scanf("%d", &x);
	node = Search(x, tree); 
	if(node != NULL) {
		printf(" tim thay %d\n", x);
		printf(" nut co do cao %d \n", h(node));
		printf(" nut co do sau %d \n", depth(node, tree));
	}	
	else
		printf(" <!>: khong thay\n");


	return 0;
} 
 
 