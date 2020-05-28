#include <iostream>
using namespace std;

struct NODE{
	int Data;
	struct NODE *next;
};

typedef struct NODE Node;

typedef struct{
	Node* Front;
	Node* Rear;
}Queue;

Node* GetNode(int x){
	Node* p = new Node;
	
	if (p == NULL){
		cout << "\nKhong du bo nho de cap phat!";
		return NULL;
	}
	p->Data = x;
	p->next = NULL;
	return p;
}

void MakeNull(Queue &q){
	q.Front = q.Rear = NULL;
}

bool isEmpty(Queue q){
	if (q.Front == NULL){
		return true;
	}
	return false;
}

void EnQueue(int x, Queue &q){
	Node* p = GetNode(x);
	if (isEmpty(q) == true){
		q.Front = q.Rear = p; 
		return;
	}
	
	q.Rear->next = p;
	q.Rear = p;
}

void DeleteQueue(int &x, Queue &q){
	if (isEmpty(q) == true){
		cout << "\nLoi hang rong!";
		return;
	}
	
	Node* p = q.Front;
	x = p->Data;
	q.Front = q.Front->next;
	delete p;
}

void Top(Queue &q){
	if (isEmpty(q) == true){
		cout << "\nLoi hang rong!";
		return;
	}
	cout << q.Front->Data;
}

void OutPut(Queue &q){
	if (isEmpty(q) == true){
		cout << "\nLoi hang rong!";
		return;
	}
	
	while (isEmpty(q) == false){
		int x;
		DeleteQueue(x, q);
		cout << x << "   ";
	}
}

void DoFunction(Queue &q){
	while (true){
		system("cls");
        cout <<"\t\t=========Menu==========";
        cout <<"\n\t\t1. Them phan tu vao Queue - EnQueue";
        cout <<"\n\t\t2. Lay phan tu dau tien ra khoi Queue - DeleteQueue";
        cout <<"\n\t\t3. Xem phan tu dau tien trong Queue - Top";
        cout <<"\n\t\t4. Lay ra tat ca phan tu trong Queue - OutPut";
        cout <<"\n\t\t5. Kiem tra Queue rong - isEmpty";
        cout <<"\n\t\t0. Ket thuc";
        cout <<"\n\t\t=========End==========";
        int op;
        cout << "\nNhap vao lua chon cua ban: ";
        cin >> op;
        if (op == 1){
        	int x;
        	cout << "\nNhap phan tu can them: ";
        	cin >> x;
        	EnQueue(x, q);
		}
		else if (op == 2){
			int x;
			DeleteQueue(x, q);
			cout << "\nPhan tu dau tien la: " << x;
			system("pause");
		}
		else if (op == 3){
			cout << "Phan tu dau tien la: ";
			Top(q);
			system("pause");
		}
		else if (op == 4){
			cout << "\nCac phan tu trong Queue: ";
			OutPut(q);
			system("pause");
		}
		else if (op == 5 ){
			if(isEmpty(q)){
				cout << "\nDanh sach rong!!" <<endl;
			}
			else{
				cout << "\nDanh sach co phan tu!" << endl;
			}
			system("pause");
		}
		else{
			break;
		}
	}
}

int main(){
	Queue q;
	MakeNull(q);
	DoFunction(q);
}
