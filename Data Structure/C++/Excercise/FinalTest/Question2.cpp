#include <iostream>
using namespace std;
#include <string.h>
#include <queue>

struct NODE{
	string Data;
	struct NODE *left;
	struct NODE *right;
};


typedef NODE Node;
typedef Node* Tree;


void MakeNull(Tree &t){
	t = NULL;
}


bool empty(Tree t){
	return t == NULL;
}


Node* GetNode(string x){
	Node* p = new Node;
	
	p->Data = x;
	p->left = p->right = NULL;
	return p;
}


Node* Create2(string v, Tree t1, Tree t2){
	Node* p = GetNode(v);
	
	p->left = t1;
	p->right = t2;
	return p;
}


void Question2c(Tree t){
	if (empty(t)) return;
	queue<Tree> theq;
	theq.push(t);
	
	while (theq.size() > 0){
		Node* p = new Node;
		p = theq.front();
		cout << "\t" << p->Data;
		theq.pop();
		
		if (p->left != NULL){
			theq.push(p->left);
		}
		
		if (p->right != NULL){
			theq.push(p->right);
		}
	}
}


// cac ham duyet

//1. duyet tien tu:
void NLR(Tree t){
	if (!empty(t)){
		cout << "\t" << t->Data;
		NLR(t->left);
		NLR(t->right);
	}
}

//2. Thu tuc duyet trung tu:
void LNR(Tree t){
	if (!empty(t)){
		LNR(t->left);
		cout << "\t" << t->Data;
		LNR(t->right);
	}
}


//3. Thu tuc duyet hau tu:
void LRN(Tree t){
	if (!empty(t)){
		LRN(t->left);
		LRN(t->right);
		cout << "\t" << t->Data;
	}
}



void DoFunction(){
	Tree t;
	MakeNull(t);
	while (true){
		system("cls");
        cout <<"\t\t=========Menu==========";
        cout <<"\n\tPress  1: Cau2a - Thu tuc duyet";
        cout <<"\n\tPress  2: Cau2b - Tao cay";
        cout <<"\n\tPress  3: Cau2c - Thu tuc duyet cay theo muc";
        cout <<"\n\tPress  0: End the program!";
        cout <<"\n\t\t=========End==========";
        int op;
        cout << "\nEnter your option: ";
        cin >> op;
        if (op == 0){
        	break;
		}
		else if (op == 1){
			system("cls");
			cout << "\n\t\tCac ham duyet!!!!\n\n";
			cout << "\t1. Duyet tien tu (NLR) \n";
			cout << "\t2. Duyet trung tu (LNR) \n";
			cout << "\t3. Duyet hau tu (LRN) \n";
			cout << "\nNhap vao lua chon cua ban: ";
			int n;
			cin >> n;
			
			if (n == 1){
				cout << "\nDuyet tien tu: ";
				NLR(t);
			}
			else if (n == 2){
				cout << "\nDuyet trung tu: ";
				LNR(t);
			}
			else if (n == 3){
				cout << "\nDuyet hau tu: ";
				LRN(t);
			}
			cout << "\n";
			system("pause");
		}
		else if (op == 2){
			t = Create2("A", Create2("B", Create2("D", NULL, NULL), Create2("E", NULL, Create2("H", NULL, NULL))), Create2("C", Create2("F", NULL, NULL), Create2("G", NULL, NULL)));
		}
		else if (op == 3){
			Question2c(t);
			cout << endl;
			system("pause");
		}
	}
}


int main(){
	DoFunction();
	/*
	queue<int> q;
	int bao;
	q.push(10);
	bao = q.front();
	
	cout << bao;
	*/
	return 0;
}
