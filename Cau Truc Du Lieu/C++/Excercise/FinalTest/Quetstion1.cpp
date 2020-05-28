#include <iostream>
using namespace std;

struct NODE{
	int Data;
	struct NODE *pNext;
};
typedef struct NODE Node;


typedef struct{
	Node *head;
	Node *tail;
} List;


Node* GetNode(int x){
	Node* p = new Node;
	
	if (p == NULL){
		cout << "\nNot enough memory!\n";
	}
	
	p->Data = x;
	p->pNext = NULL;
	return p;
}


void MakeNull(List &l){
	l.head = l.tail = NULL;
}


bool isEmpty(List l){
	return l.head == NULL;
}


void Addtail(int x, List &l){
	Node* p = GetNode(x);
	
	if (isEmpty(l)){
		l.head = l.tail = p;
		return;
	}
	
	l.tail->pNext = p;
	l.tail = p;
}

void AddHead(int x, List &l){
	Node* p = GetNode(x);
	
	if (isEmpty(l)){
		l.head = l.tail = p;
		return;
	}
	
	p->pNext = l.head;
	l.head = p;
}


void SortList(List &l){
	for (Node* i = l.head; i != l.tail; i = i->pNext){
		for (Node* j = i->pNext; j != NULL; j = j->pNext){
			if (i->Data > j->Data){
				int temp = i->Data;
				i->Data = j->Data;
				j->Data = temp;
			}
		}
	}
}


void InsertNode(int x, List &l){
	if (isEmpty(l)) return;
	
	if (x <= l.head->Data) AddHead(x, l);
	
	else if (x >= l.tail->Data) Addtail(x, l);
	
	else{
		Node* p = GetNode(x);
		
		for (Node* i = l.head; i != NULL; i = i->pNext){
			if (i->pNext->Data > x){
				p->pNext = i->pNext;
				i->pNext = p;
				return;
			}
		}
	}
}


void InsertNode2(int x, List &l){
	if (isEmpty(l)) return;
	
	if (x >= l.head->Data) AddHead(x, l);
	
	else if (x <= l.tail->Data) Addtail(x, l);
	
	else{
		Node* p = GetNode(x);
		
		for (Node* i = l.head; i != NULL; i = i->pNext){
			if (i->pNext->Data < x){
				p->pNext = i->pNext;
				i->pNext = p;
				return;
			}
		}
	}
}


void CreateList(List &l){
	MakeNull(l);
	int n, x;
	cout << "\nNhap so phan tu ban muon them: ";
	cin >> n;
	
	for (int i=0; i < n; i++){
		cout << "\nNhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		Addtail(x, l);
	}	
}


int SumOfAllNode(List &l){
	int sum;
	sum = 0;
	for (Node* i = l.head; i != NULL; i = i->pNext){
		sum += i->Data;
	}
	return sum;
}


void PartC(List &l){
	List l1, l2;
	MakeNull(l1);
	MakeNull(l2);
	
	cout << "Danh sach dau tien: \n";
	CreateList(l1);
	system("cls");
	cout << "Danh sach thu hai: \n";
	CreateList(l2);
	system("cls");
	SortList(l1);
	SortList(l2);
	for (Node* i = l1.head; i != NULL; i = i->pNext){
		int x;
		x = i->Data;
		AddHead(x, l);
	}
	
	for (Node* i = l2.head; i != NULL; i = i->pNext){
		int x;
		x = i->Data;
		InsertNode2(x, l);
	}
}


void OutPut(List l){
	for (Node* i = l.head; i != NULL; i = i->pNext){
		cout << "\t" << i->Data;
	}
	cout << endl;
}


void Question1(){
	while (true){
		system("cls");
		cout << "\n\n\t\t============Options============";
		cout<<"\n\tPress 1: 1a). Them phan tu x vao danh sach co thu tu ";
		cout<<"\n\tPress 2: 1b). Ham tra ra tong gia tri cac phan tu trong danh sach";
		cout<<"\n\tPress 3: 1c). Tron 2 danh sach co thu tu tang de duoc 1 danh sach co thu tu giam";
		cout<<"\n\tPress 0: KetThuc ";
		cout << "\n\n\t\t=============Ends=============";
		int op;
		cout << "\nNhap vao lua chon cua ban: ";
		cin >> op;
		if (op == 1){
			system("cls");
			cout << "\n\t\tCAU 1A\n\n";
			List l;
			CreateList(l);
			SortList(l);
			cout << "\nDanh sach: ";
			OutPut(l);
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			InsertNode(x, l);
			cout << "\n\nDanh sach sau khi them: ";
			OutPut(l);
			system("pause");
		}
		else if (op == 2){
			cout << "\n\t\tCAU 1B\n\n";
			system("cls");
			List l;
			CreateList(l);
			cout << "\nDanh sach: ";
			OutPut(l);
			int x;
			x = SumOfAllNode(l);
			cout << "\nTong gia tri cua cac phan tu la: " << x << endl;
			system("pause");
		}
		else if (op == 3){
			cout << "\n\t\tCAU 1C\n\n";
			system("cls");
			List l;
			MakeNull(l);
			PartC(l);
			cout << "\nDanh sach tron la: ";
			OutPut(l);
			system("pause");
		}
		else if (op == 0){
			break;
		}
	}
}


int main(){
	Question1();
	return 0;
}
