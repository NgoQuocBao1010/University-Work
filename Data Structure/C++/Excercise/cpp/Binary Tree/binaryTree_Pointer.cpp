#include <iostream>
using namespace std;

struct NODE{
	int Data;
	struct NODE *pLeft;
	struct NODE *pRight;
};

typedef struct NODE Node;
typedef Node* Tree;

//Khoi tao cay
void MakeNull(Tree &t){
	t = NULL; 
}

void InSert(Tree &t, int x){
	if (t == NULL){
		// cay rong thi x la NODE goc
		Node *q = new Node;
		q->Data = x;
		q->pLeft = q->pRight = NULL;
		t = q; // t tro den q
	}
	else
	{
		if (t->Data > x){
			InSert(t->pLeft, x);
		}
		else if(t->Data < x){
			InSert(t->pRight, x);
		}
	}
}

// tao 1 cay
void CreateTree(Tree &t){
	MakeNull(t);
	int LuaChon;
	do{
		
		cout<<"\n1.Them du lieu.";
		cout<<"\n2.Ket thuc";
		cout<<"\nNhap vao lua chon cua ban: ";
		cin >> LuaChon;
		
		if (LuaChon == 1){
			int x;
			cout<<"\nNhap du lieu can them: ";
			cin >> x;
			
			InSert(t, x); // them x vao cay
		}
	}while (LuaChon != 2);
}

//Xoa cac Node khong co con hoac co 1 con
void DeleteNode(Tree &t, int x){
	if (t == NULL){
		return;
	}
	
	if (t->Data > x){
		DeleteNode(t->pLeft, x);
	}
	else if (t->Data < x){
		DeleteNode(t->pRight, x);
	}
	else{
		Node *p = t;
		
		if (t->pLeft == NULL){
			t = t->pRight;
		}
		else if (t->pRight == NULL){
			t = t->pLeft;
		}
		delete p;
	}
}

//tim kiem cac Node
bool Search(Tree t, int x){
	if (t == NULL){
		cout < "\nPhan tu khong ton tai trong cay.";
		return false;
	}
	
	if (t->Data > x){
		Search(t->pLeft, x);
	}
	else if (t->Data < x){
		Search(t->pRight, x);
	}
	else{
		cout << "\nPhan tu " << x << " co ton tai trong cay";
		return true;
	}
}


// cac ham duyet
void NLR(Tree t){
	if (t != NULL){
		cout << t->Data << "   ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

void LNR(Tree t){
	if (t != NULL){
		LNR(t->pLeft);
		cout << t->Data << "   ";
		LNR(t->pRight);
	}
}

void LRN(Tree t){
	if (t != NULL){
		LRN(t->pLeft);
		LRN(t->pRight);
		cout << t->Data << "   ";
	}
}

void NRL(Tree t){
	if (t != NULL){
		cout << t->Data << "   ";
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}

void RNL(Tree t){
	if (t != NULL){
		RNL(t->pRight);
		cout << t->Data << "   ";
		RNL(t->pLeft);
	}
}


void RLN(Tree t){
	if (t != NULL){
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << t->Data << "   ";
	}
}

int main(){
	Tree t;
	int x;
	CreateTree(t);
	NLR(t);
	cout <<"\nNhap phan tu can them: ";
	cin >> x;
	InSert(t, x);
	cout << "\nDanh sach sau khi them: ";
	NLR(t);
	return 0;
}




