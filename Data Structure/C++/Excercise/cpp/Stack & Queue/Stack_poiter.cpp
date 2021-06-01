#include <iostream>
using namespace std;

struct NODE{
	int Data;
	struct NODE *pNext;
};
typedef struct NODE Node;

struct stack{
	NODE *pTop;
};
typedef struct stack Stack;

//khoi tao Stack
void Init(Stack &s){
	s.pTop = NULL;
}

bool isEmpty(Stack s){
	if (s.pTop == NULL){
		return true;
	}
	return false;
}

//tao ra 1 cai NODE
Node *InitNode(int x){
	Node *p = new Node();
	if (p == NULL){
		cout <<"\nKhong du bo nho de cap phat!";
		return NULL;
	}
	p->Data = x;
	p->pNext = NULL;
	return p;
}

void Push(Stack &s, int x){
	Node* p = InitNode(x);
	if (isEmpty(s) == true){
		s.pTop = p;
	}
	else{
		p->pNext = s.pTop;
		s.pTop = p;
	}
}

void Pop(Stack &s, int &x){
	if (isEmpty(s) == true){
		return;
	}
	else{
		Node *p = s.pTop;
		x = p->Data;
		s.pTop = s.pTop->pNext;
		delete p;
	}
}

void Top(Stack &s, int &x){
	if (isEmpty(s) == true){
		return;
	}
	x = s.pTop->Data;
	return;
}


void Output(Stack &s){
	while(isEmpty(s) == false){
		int x;
		Pop(s, x);
		cout << x << ' ';
	}
	if (isEmpty(s) == true){
		cout << "\nDanh sach da bi rong!\n";
	}
}

void CreateStack(Stack &s){
	while (true){
		system("cls");
		int option;
		cout << "\n\n\t\t======Options======";
		cout<<"\n\t\t1. Them phan tu vao Stack - Push";
		cout<<"\n\t\t2. Xem Stack - Pop";
		cout<<"\n\t\t3. Xem phan tu dau cua danh sach - Top";
		cout<<"\n\t\t0. Ket thuc";
		cout<<"\n\t\t=======End=======\n";
		cout<<"\nNhap vao lua chon cua ban: ";
		cin >> option;
		
		if (option == 1){
			int x;
			cout << "\nNhap phan tu can them vao: ";
			cin >> x;
			Push(s, x);
		}
		else if (option == 2){
			Output(s);
			system("pause");
		}
		else if (option == 3){
			int x;
			Top(s, x);
			cout << "\nPhan tu dau cua danh sach la: " << x<<endl;
			system("pause");
		}
		else{
			break;
		}
	}
}



int main(){
	Stack s;
	Init(s);
	CreateStack(s);
}


