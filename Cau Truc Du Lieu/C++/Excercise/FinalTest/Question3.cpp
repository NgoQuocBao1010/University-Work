#include <iostream>
using namespace std;

struct NODE{
	int Data;
	struct NODE *left;
	struct NODE *right;
};

typedef struct NODE Node;
typedef Node* Tree;


void MakeNull(Tree &t){
	t = NULL;
}


bool isEmpty(Tree t){
	return t == NULL;
}


void InsertTree(int x, Tree &t){
	if (t == NULL){
		Node* p = new Node;
		p->Data = x;
		p->left = p->right = NULL;
		t = p;
		return;
	}
	
	if (x > t->Data){
		InsertTree(x, t->right);
	}
	
	if (x < t->Data){
		InsertTree(x, t->left);
	}
}


void RightMostLeft(Tree &p, Tree &q){
	if (q->right != NULL){
		RightMostLeft(p, q->right);
	}
	else{
		p->Data = q->Data;
		p = q;
		q = q->left;
	}
}


void Delete(int x, Tree &t){
	if (isEmpty(t)){
		return;
	}
	
	if (x > t->Data){
		Delete(x, t->right);
	}
	else if (x < t->Data){
		Delete(x, t->left);
	}
	else{
		Node* p = t;
		if (t->right == NULL){
			t = t->left;
		}
		else if (t->left == NULL){
			t = t->right;
		}
		else{
			RightMostLeft(p, p->left);
		}
		delete p;
	}
}


// cac ham duyet
void NLR(Tree t){
	if (t != NULL){
		cout << t->Data << "   ";
		NLR(t->left);
		NLR(t->right);
	}
}

void LNR(Tree t){
	if (t != NULL){
		LNR(t->left);
		cout << t->Data << "   ";
		LNR(t->right);
	}
}

void LRN(Tree t){
	if (t != NULL){
		LRN(t->left);
		LRN(t->right);
		cout << t->Data << "   ";
	}
}


void CreateTree(Tree &t){
	MakeNull(t);
	int n;
	cout << "\nNhap so phan tu trong cay: ";
	cin >> n;
	
	for (int i = 1; i <= n; i ++ ){
		int x;
		cout << "\nNhap phan tu thu " << i << " : ";
		cin >> x;
		InsertTree(x, t);
	}
}


void CreateTree2(Tree &t){
	// tao 1 cai cay giong de bai
	MakeNull(t);
	
	int A[10] = {35, 20, 0, 56, 50, 70, 25, 90, 57, 30};
	
	for (int i = 0; i < 10; i++){
		InsertTree(A[i], t);
	}
}


void Question2(){
	while (true){
		system("cls");
		cout << "\n\n\t\t============Options============";
		cout<<"\n\tPress 1: 1a). Ve hinh minh hoa (Lam trong giay) ";
		cout<<"\n\tPress 2: 1b). Lan luot xoa cac nut 56, 70, 90";
		cout<<"\n\tPress 3: 1c). Viet khai bao va thu tuc them 1 khoa x vao cay";
		cout<<"\n\tPress 0: KetThuc ";
		cout << "\n\n\t\t=============Ends=============";
		int op;
		cout << "\nNhap vao lua chon cua ban: ";
		cin >> op;
		if (op == 1){
			system("cls");	
			cout << "\n\tCAU 1A\n\t\tLAM TRONG GIAY!!!\n";
			system("pause");
		}
		else if (op == 2){
			system("cls");	
			cout << "\n\t\tCAU 1B\n";
			Tree t;
			MakeNull(t);
			CreateTree2(t);
			cout << "\nDanh sach : \n";
			NLR(t);
			Delete(56, t);
			cout << "\n\nDanh sach sau khi xoa 56: \n";
			NLR(t);
			Delete(70, t);
			cout << "\n\nDanh sach sau khi xoa 70: \n";
			NLR(t);
			Delete(90, t);
			cout << "\n\nDanh sach sau khi xoa 90: \n";
			NLR(t);
			cout << endl;
			system("pause");
		}
		else if (op == 3){
			Tree t;
			CreateTree2(t);
			system("cls");	
			cout << "\n\t\tCAU 1C\n";
			cout << "\nNhap so ban muon them: ";
			int x;
			cin >> x;
			InsertTree(x, t);
			cout << "\nDanh sach sau khi them: ";
			NLR(t);
			system("pause");
		}
		else{
			break;
		}
	}
}


int main(){
	Question2();
	return 0;
}
