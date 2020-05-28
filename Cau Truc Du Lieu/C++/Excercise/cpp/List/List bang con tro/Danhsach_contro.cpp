#include <iostream>
#include <conio.h>

using namespace std;


// Khai bao cau truc du lieu NODE va danh sach
struct NODE{
	int Data;
	struct NODE *pNext;
};

typedef struct NODE Node;

typedef struct{
	Node *pHead;
	Node *pTail;
}List;

// Khoi tao danh sach
void MAKE_NULL(List &l){
	l.pHead = l.pTail = NULL;
}

// Tao ra 1 cai NODE, dua Data vao NODE
Node* GetData(int x){
	Node *p = new Node; // cap phat du lieu
	
	if (p == NULL){
		return NULL;
	}
	
	p->Data = x; // tuong tu nhu p.Data (Luu x vao Data)
	p->pNext = NULL; 
	return p;
}

// Them NODE vao cuoi
void Add(List &l, Node *p){
	if ( l.pHead == NULL) //Danh sach bi rong
		l.pHead = l.pTail = p;
	
	else { // Neu Danh sach khong rong
		l.pTail->pNext = p; //tao lien ket
		l.pTail = p; // p tro thanh tail
	}
}

//them NODE vao dau
void Reverse_Add(Node *p, List &l){
	if ( l.pHead == NULL) //Danh sach bi rong
		l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

// giai phong list
void FreeList(List &l){
	Node *p;
	while(l.pHead != NULL){
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

// nhap du lieu cho danh sach
void READ(List &l){
	int n;
	MAKE_NULL(l);
	cout<<"Nhap so phan tu cua danh sach: "; // So luong NODE
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		int x;
		cout<< "So phan tu thu "<<i<<" la: ";
		cin >> x;
		
		Node *p = GetData(x); // Dua Du lieu vao NODE
		Add(l, p); // Them NODE vao Danh Sach		
	}
}


//dem so le
int CountOdd(List &l){
	int count = 0;
	for (Node *p = l.pHead; p != NULL; p = p->pNext){
		if (p->Data % 2 != 0) count++;
	}
	return count;
}


void PRINT(List l){
	cout<<"Danh Sach: ";
	for (Node *p = l.pHead; p != NULL; p = p->pNext)
		cout<<p->Data<<" ";
}


// in nguoc lai
void BT1b(List &l){
	List l1;
	MAKE_NULL(l1);
	
	for (Node *p = l.pHead; p != NULL; p=p->pNext){
		int x;
		x = p->Data;
		Node *q = GetData(x);
		Reverse_Add(q, l1);
	}
	PRINT(l1);
	
}

//sap xep cac phan tu
void Sort(List &l){
	int temp = 0;
	for (Node *p = l.pHead; p != l.pTail ; p = p->pNext){
		for (Node *p1 = p->pNext; p1 != NULL ; p1 = p1->pNext){
			if ( p->Data > p1->Data){
				temp = p->Data;
				p->Data = p1->Data;
				p1->Data = temp;
			}
		}
	}
}

//tim so lon nhat
int Max(List &l){
	int max = l.pHead->Data;
	for (Node *p = l.pHead->pNext; p != NULL; p = p->pNext){
		if (p->Data > max){
			max = p->Data;
		}
	}
	return max;
}

//them vao phia sau 1 node
void INSERT(Node *a, Node *p, List &l){
	
	for (NODE *i = l.pHead; i != NULL; i = i->pNext){
		if (i->Data == p->Data){
			Node *j = i->pNext;
			i->pNext = a;
			a->pNext = j;
		}
	}
}

// Tim Node dung truoc
Node* NodeInfrt(int x, List &l){
	Node *p;
	for (Node *p = l.pHead; p != NULL; p = p->pNext){
		if (p->pNext->Data == x ){
			return p;
		}
	}
}


// them vao truoc
void INSERT_BEFORE(Node *a, Node *p, List &l){
	
	for (NODE *i = l.pHead; i != NULL; i = i->pNext){
		if (i->Data == p->Data){
			Node* j = NodeInfrt(i->Data, l);
			j->pNext = a;
			a->pNext = i;
		}
	}
}


// them vao 1 cach co sap xep
int Bt4(int x, List &l){
	if (x >= l.pTail->Data) Add(l, GetData(x));
	else
		if (x <= l.pHead->Data) Reverse_Add(GetData(x), l);
		
		else {
			for (Node *p = l.pHead; p != NULL; p = p->pNext){		
				if (x <= p->Data) {
					INSERT_BEFORE( GetData(x), p, l);
					break;
				}
			}
		}
}

// tra ve 1 Node co gia tri la x
Node* Locate(int x, List &l){
	for (Node *p = l.pHead; p; p=p->pNext){
		if (x == p->Data)
			return p;
	}
	return NULL;
}

// xoa 1 cai Node
void DeleteNode(Node* p, List &l){
	
	if (p->Data == l.pHead->Data){
		Node* m = l.pHead->pNext;
		l.pHead->pNext = NULL;
		l.pHead = m;
	}
	else if(p->Data == l.pTail->Data){
			Node* k = NodeInfrt(l.pTail->Data, l);
			k->pNext = NULL;
			l.pTail = k;
	}
		else {
			for (Node *i = l.pHead; i; i = i->pNext){
				if ( p->Data == i->Data){
					Node *m = NodeInfrt(i->Data, l);
					Node *n = i->pNext;
					m->pNext = n;
					break;
				}
			}
		}
}


void DeleteHead(List &l){
	Node *p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}

void DeleteTail(List &l){
	for (Node *i = l.pHead; i != NULL; i = i->pNext){
		if (i->pNext == l.pTail){
			Node *p = l.pTail;
			l.pTail = i;
			l.pTail->pNext = NULL;
			delete p;
			return;
		}
	}
}
// them vao 1 danh sach 1 cach co sap xep
void Bt6(List &l){
	List l1;
	READ(l1);
	Sort(l1);
	
	for (Node *p = l1.pHead; p; p = p->pNext){
		Bt4(p->Data, l);
	}
}


/*
void Bt7(List &l){
	for (Node *p = l.pHead; p->pNext != l.pTail; p = p->pNext){
		for (Node *q = l.pHead->pNext; q; q = q->pNext){
			if (Locate())
		}
	}
}

*/

// them vao 1 list nhung loai bo cac phan tu trung
void Bt8(List &l){
	List l1;
	READ(l1);
	
	for (Node* p = l1.pHead; p != NULL; p = p->pNext){
		if ( Locate(p->Data, l) == NULL){
			Bt4(p->Data, l);
		}
	}
}

void Bt9(List &l){
	MAKE_NULL(l);
	List l1,l2;
	READ(l1);
	READ(l2);
	
	for (Node* p= l1.pHead; p != NULL; p = p->pNext){
		int x;
		x = p->Data;
		Node *a = GetData(x);
		Add(l, a);
	}
	
	for (Node* p= l2.pHead; p != NULL; p = p->pNext){
		Bt4(p->Data, l);
	}
}

void Bt10(List &l){
	
	while ( CountOdd(l) > 0){
		for (Node* p= l.pHead; p != NULL; p = p->pNext) {
			if (p->Data % 2 != 0)
				DeleteNode(p, l);			
		}
	}
}

void Bt11(List &l){
	List l1;
	MAKE_NULL(l1);
	List l2;
	MAKE_NULL(l2);
	
	for (Node* p = l.pHead; p != NULL; p = p->pNext){
		if (p->Data % 2 == 0){
			int x;
			x = p->Data;
			Node *a = GetData(x);
			Add(l1, a);
		}
		else{
			int y;
			y = p->Data;
			Node *c = GetData(y);
			Add(l2, c);
		} 
	}
	PRINT(l1); cout<<"\n";
	PRINT(l2);
}

int main(){
	int n;
	List l;
	READ(l);
	
	PRINT(l);
	DeleteTail(l);
	PRINT(l);
	FreeList(l);
	
	return 0;
}


