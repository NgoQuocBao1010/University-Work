#include <iostream>
#include <string.h>
using namespace std;

#define MaxLength 10
typedef string ElementType;

typedef struct{
	ElementType Elements[MaxLength];
	int Front, Rear;
}Queue;

void MakeNull(Queue &q){
	q.Front = q.Rear = -1;
}

bool isEmpty(Queue q){
	if (q.Front == -1 ){
		return true;
	}
	return false;
}

bool FullQueue(Queue q){
	if (q.Rear - q.Front + 1 == MaxLength){
		return true;
	}
	return false;
}

void EnQueue(ElementType s, Queue &q){
	if (FullQueue(q) == false){
		if (isEmpty(q) == true){
			q.Front = 0;
			q.Rear ++;
			q.Elements[q.Rear] = s;
		}
		else{
			q.Rear ++;
			q.Elements[q.Rear] = s;
		}
	}
	else{
		cout << "\nLoi hang day!!" << endl;
		system("pause");
	}
}

void DeQueue(Queue &q){
	if (isEmpty(q) == false){
		q.Elements[q.Front] = "";
		q.Front ++;
		if (q.Front > q.Rear )
			MakeNull(q);
	}
	else{
		cout << "\nHang rong!!" << endl;
	}
}

void Top(Queue q){
	cout << q.Elements[q.Front] ;
}

void ReadQueue(Queue &q){
	int n;
	cout << "\nNhap so phan tu can them: ";
	cin >> n;
	cout << "\nNhap cac phan tu: ";
	for (int i = 0; i < n; ++i){
		string s;
		cin >> s;
		EnQueue(s, q);
	}	
}

void OutPut(Queue &q){
	if (isEmpty(q) == true){
		cout << "\nLoi hang rong!" << endl;
	}
	while(isEmpty(q) == false){
		Top(q);
		cout << "   ";
		DeQueue(q);
	}
}

void Bt19_buffer(Queue &q){
	char file_doc[50], file_ghi[50];
	cout << "\nNhap ten file de doc: ";
	cin >> file_doc;
	
	cout << "\nNhap ten file de ghi: ";
	cin >> file_ghi;
	
	freopen(file_doc, "r", stdin);
	freopen("thuan.txt", "w", stdout);
	while (true){
		string s;
		getline(cin, s);
		if (s == "\0") break;
		EnQueue(s, q);
	}
	
	while(isEmpty(q) == false){
		Top(q);
		cout <<"\n";
		DeQueue(q);
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
        	string s;
        	cout << "\nNhap phan tu can them: ";
        	cin >> s;
        	EnQueue(s, q);
		}
		else if (op == 2){
			int x;
			DeQueue(q);
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
	Bt19_buffer(q);
	return 0;
}

