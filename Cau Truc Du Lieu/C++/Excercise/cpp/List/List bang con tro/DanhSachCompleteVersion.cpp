#include <iostream>

using namespace std;

struct NODE{
	int Data;
	struct NODE *pNext;
};


typedef struct NODE Node;


typedef struct{
	Node *Head;
	Node *Tail;
}List;


void MakeNull(List &l){
	l.Head = l.Tail = NULL;
	return;
}

bool isEmpty(List l){
	if (l.Head == NULL){
		return true;
	}
	return false;
}

Node *GetNode(int x){
	Node *p = new Node;
	
	if (p == NULL){
		cout << "\nKhong du bo nho!";
	}
	
	p->Data = x;
	p->pNext = NULL;
	return p;
}

void AddTail(int x, List &l){
	Node* p = GetNode(x);
	if (isEmpty(l) == true){
		l.Head = l.Tail = p;
		return;
	}
	
	l.Tail->pNext = p;
	l.Tail = p;
}

void AddHead(int x, List &l){
	Node* p = GetNode(x);
	if (isEmpty(l) == true){
		l.Head = l.Tail = p;
		return;
	}
	
	p->pNext = l.Head;
	l.Head = p;
}

void SortList(List &l){
	for (Node* p = l.Head; p != l.Tail; p = p->pNext){
		for (Node* q = p->pNext; q != NULL; q = q->pNext){
			if (p->Data > q->Data){
				int temp = p->Data;
				p->Data = q->Data;
				q->Data = temp;
			}
		}
	}
}

void CreateList(List &l){
	MakeNull(l);
	int n, x;
	cout << "\nNhap so phan tu cua danh sach: ";
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		cout << "\nPhan tu thu " << i << " la: ";
		cin >> x;
		
		AddTail(x, l);
	}
}

void InsertNode(int x, int y, List &l){
	Node* q = GetNode(x);
	if (l.Tail->Data == y){
		AddTail(x, l);
		return;
	}
	for (Node* i = l.Head; i!= l.Tail; i = i->pNext){
		if (i->Data == y){
			Node* k = i->pNext;
			i->pNext = q;
			q->pNext = k;
			return;
		}
	}
	cout << "\nKhong co phan tu "<< y << " trong danh sach";
	return;
}

int LocateAndCount(int x, List &l){
	if (isEmpty(l) == true){
		cout << "\nDanh sach rong!";
		return 0;
	}
	else{
		int count=0;
		for (Node* i = l.Head; i != NULL; i = i->pNext){
			if (i->Data == x){
				++count;
			}
		}
		return count;
	}
}
void DeleteHead(List &l){
	Node* p = l.Head;
	l.Head = l.Head->pNext;
	delete p;
}

void DeleteTail(List &l){
	for (Node* i = l.Head; i != l.Tail; i = i->pNext){
		if (i->pNext == l.Tail){
			Node* p = l.Tail;
			l.Tail = i;
			l.Tail->pNext = NULL;
			delete p;
			return;
		}
	}
}

void DeleteNode(int x, List &l){
	if (l.Head->Data == x){
		DeleteHead(l);
	}
	else if(l.Tail->Data == x){
		DeleteTail(l);
	}
	else{
		for (Node* i = l.Head->pNext; i != l.Tail; i = i->pNext){
			if (i->pNext->Data == x){
				Node* k = i->pNext;
				i->pNext = k->pNext;
				delete k;
				return;
			}
		}
		cout << "\nKhong co phan tu " << x << " trong danh sach.";
	}
}

void OutPut(List l){
	for (Node *i = l.Head; i != NULL; i = i->pNext){
		cout << i->Data << "  ";
	}
	cout << "\n\n";
}

void Bt1b(List &l){
	List l1;
	MakeNull(l1);
	for (Node* i = l.Head; i != NULL; i = i->pNext){
		AddHead(i->Data, l1);
	}
	cout << "\nDanh Sach in nguoc la: ";
	OutPut(l1);	
}

void Bt4(int x, List &l){
	if (isEmpty(l) == true){
		AddTail(x, l);
		return;
	}
	if (x >= l.Tail->Data){
		AddTail(x, l);
		return;
	}
	if (x <= l.Head->Data){
		AddHead(x, l);
		return;
	}
	for (Node* i = l.Head; i != NULL; i = i->pNext){
		if (i->pNext->Data > x){
			InsertNode(x, i->Data, l);
			return;
		}
	}
}

void Bt6(List &l){
	int n , A[100];
	cout << "\nNhap so phan tu can them: ";
	cin >> n;
	cout << "\nNhap cac phan tu: ";
	for (int i = 0; i < n; ++i){
		cin >> A[i];
	}
	for (int i = 0; i < n; ++i){
		Bt4(A[i], l);
	}	
}

void Bt7(List &l){
	List l1;
	MakeNull(l1);
	for (Node* i = l.Head; i != NULL; i = i->pNext){
		int x = i->Data;
		if (LocateAndCount(x, l1) == 0){
			AddTail(x, l1);
		}
	}
	MakeNull(l);
	for (Node* i = l1.Head; i != NULL; i = i->pNext){
		int x = i->Data;
		AddTail(x, l);
	}
}

void Bt8(List &l1, List &l){
	SortList(l1);
	Bt7(l1);
	
	for (Node* i = l1.Head; i != NULL; i = i->pNext){
		if (LocateAndCount(i->Data, l) == 0){
			Bt4(i->Data, l);
		}
	}
}

void Bt9(List l1, List l2, List &l){
	MakeNull(l);
	
	for (Node* i = l1.Head; i != NULL; i = i->pNext){
		Bt4(i->Data, l);
	}
	
	Bt8(l2, l);
	return;
}

void DoFunction(List &l){
	bool Operated = false;
	while (true){
		system("cls");
		cout << "\n\n\t\t============Options============";
		cout<<"\n\t1. Them vao dau danh sach - AddHead ";
		cout<<"\n\t2. Kiem tra danh sach rong - isEmpty ";
		cout<<"\n\t3. Them 1 Node vao sau 1 Node - InsertNode ";
		cout<<"\n\t4. Them vao cuoi danh sach - AddTail ";
		cout<<"\n\t5. Tim kiem va tra ve so luong phan tu - LocateAndCount ";
		cout<<"\n\t6. In ra danh sach - Output ";
		cout<<"\n\t7. Xoa phan tu dau danh sach - DeleteHead ";
		cout<<"\n\t8. Xoa phan tu cuoi danh sach - DeleteTail ";
		cout<<"\n\t9. Xoa phan bat ky trong danh sach - DeleteNode ";
		cout<<"\n\t10. Sap xep lai danh sach - SortList ";
		cout<<"\n\t11. In danh sach nguoc lai - Bt1b ";
		cout<<"\n\t12. Them phan tu co sap xep - Bt4 ";
		cout<<"\n\t13. Them 1 day so nguyen 1 cach co sap xep - Bt6 ";
		cout<<"\n\t14. Xoa phan tu trung - Bt7 ";
		cout<<"\n\t15. Them 1 danh sach co dieu kien - Bt8 ";
		cout<<"\n\t16. Them 2 danh sach vao 1 danh sach 1 cach co dieu kien - Bt9 ";
		cout<<"\n\t0. KetThuc ";
		cout << "\n\n\t\t=============Ends=============";
		int option;
		cout<<"\n\nDanh sach: ";
		OutPut(l);
		cout << "\nNhap vao lua chon cua ban: ";
		cin >> option;
		
		if (option == 1){
			int x;
			cout << "\nNhap phan tu ban muon them vao dau: ";
			cin >> x;
			AddHead(x, l);
			Operated = true;
		}
		else if(option == 2){
			if (isEmpty(l) == true){
				cout << "\nDanh sach rong!";
				system("pause");
				Operated = true;
			}
			else{
				cout << "\nDanh sach co phan tu.";
				system("pause");
				Operated = true;
			}
		}
		else if(option == 3){
			int x, y;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			cout << "\nNhap phan tu dung truoc phan tu can them: ";
			cin >> y;
			InsertNode(x, y, l);
			Operated = true;
		}
		else if (option == 4){
			int x;
			cout << "\nNhap phan tu ban muon them vao cuoi: ";
			cin >> x;
			AddTail(x, l);
			Operated = true;
		}
		else if (option == 5){
			int x;
			cout << "\nNhap phan tu can tim kiem: ";
			cin >> x;
			int a = LocateAndCount(x, l);
			if (a > 0){
				cout <<"\nSo luong phan tu " << x<< " trong danh sach la: " << a;
				system("pause");
			}
			else{
				cout << "\nPhan tu khong ton tai!";
				system("pause");
			}
		}
		else if (option == 6){
			if (Operated == false){
				cout << "\nDanh Sach: ";
				OutPut(l);
				system("pause");
			}
			else{
				cout << "\nDanh Sach sau khi thay doi: ";
				OutPut(l);
				system("pause");
			}
		}
		else if (option == 7){
			DeleteHead(l);
			Operated = true;
		}
		else if (option == 8){
			DeleteTail(l);
			Operated = true;
		}
		else if (option == 9){
			cout << "\nNhap phan tu muon xoa: ";
			int x;
			cin >> x;
			
			DeleteNode(x, l);
			Operated = true;
		}
		else if (option == 10){
			SortList(l);
		}
		else if (option == 11){
			Bt1b(l);
			system("pause");
		}
		else if (option == 12){
			int x;
			cout << "\nNhap so lieu phan tu can them: ";
			cin >> x;
			Bt4(x, l);
			Operated = true;
		}
		else if (option == 13){
			Bt6(l);
		}
		else if (option == 14){
			Bt7(l);
			Operated = true;
		}
		else if (option == 15){
			List l1;
			MakeNull(l1);
			int n, x;
			cout << "\nNhap so phan tu cua danh sach can them: ";
			cin >> n;
			cout << "\nNhap cac phan tu cua danh sach can them: ";
			for (int i = 1; i <= n; i++){
				cin >> x;
				AddTail(x, l1);
			}
			Bt8(l1, l);
			Operated = true;
		}
		else if (option == 16){
			List l1, l2;
			MakeNull(l1);
			MakeNull(l2);
			int n, x;
			cout << "\nNhap so phan tu cua danh sach can them thu nhat: ";
			cin >> n;
			cout << "\nNhap cac phan tu: ";
			for (int i = 1; i <= n; i++){
				cin >> x;
				AddTail(x, l1);
			}
	
			int m, y;
			cout << "\nNhap so phan tu cua danh sach thu hai: ";
			cin >> m;
			cout << "\nNhap cac phan tu: ";
			for (int i = 1; i <= m; i++){
				cin >> y;
				AddTail(y, l2);
			}
			Bt9(l1, l2, l);
			Operated = true;
		}
		else{
			break;
		}
	}
}

int main(){
	List l;
	CreateList(l);
	DoFunction(l);
	return 0;
}
