#include <iostream>
using namespace std;

struct NODE{
	int Data;
	struct NODE *left;
	struct NODE *right;
};

typedef NODE Node;

typedef Node* Tree;

void MakeNull(Tree &t){
	t = NULL;
}

bool isEmpty(Tree t){
	return t == NULL;
}


Tree Create2(int x, Tree l, Tree r){
	Node* p = new Node;
	
	p->Data = x;
	p->left = l;
	p->right = r;
	return p;
}

bool SearchNode(int x, Tree t){
	if (isEmpty(t)){
		return false;
	}
	
	if (t->Data == x){
		return true;
	}
	else{
		if (SearchNode(x, t->left) == false){
			return SearchNode(x, t->right);
		}
		else{
			return true;
		}
	}
}

bool BT8a(int n , int m, Tree t){
	if (SearchNode(n, t) == false || SearchNode(m, t) == false || m == n){
		return false;
	}
	
	if (isEmpty(t)){
		return false;
	}
	
	if ((t->left->Data == n && t->right->Data == m) || (t->left->Data == m && t->right->Data == n)){
		return true;
	}
	else{
		if (BT8a(n, m, t->left) == false){
			return BT8a(n, m, t->right);
		}
		else{
			return true;
		}
	}
}

bool BT8b(int n, int m, Tree t){
	if (SearchNode(n, t) == false || SearchNode(m, t) == false || m == n){
		return false;
	}
	
	if (isEmpty(t)){
		return false;
	}
	
	if (t->Data == n){
		if (SearchNode(m, t)){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if (BT8b(n, m, t->left) == false){
			return BT8b(n, m, t->right);
		}
		else{
			return true;
		}
	}
}

//cac ham duyet

// tien tu-PreOrder
void NLR(Tree t){
	if (t != NULL){
		cout << t->Data << "   ";
		NLR(t->left);
		NLR(t->right);
	}
}

// hau tu-PostOrder
void LRN(Tree t){
	if (t != NULL){
		LRN(t->left);
		LRN(t->right);
		cout << t->Data << "   ";
	}
}

// trung tu-InOrder
void LNR(Tree t){
	if (t != NULL){
		LNR(t->left);
		cout << t->Data << "   ";
		LNR(t->right);
	}
}

void DoFunction(Tree &t){
	bool Operated = false;
	while (true){
		system("cls");
        cout <<"\t\t=========Menu==========";
        cout <<"\n\tPress  1: Make the Tree";
        cout <<"\n\tPress  2: Check whether the tree is Empty - isEmpty";
        cout <<"\n\tPress  3: Print Tree";
        cout <<"\n\tPress  4: Search Node";
        cout <<"\n\tPress  5: (BT8a) Check for same parrent ";
        cout <<"\n\tPress  6: (BT8b) Check ancestor ";
        cout <<"\n\tPress  0: End the program!";
        cout <<"\n\t\t=========End==========";
        int op;
        if (Operated == true){
        	cout << "\n\tMY TREE (NLR)\n   ";
        	NLR(t);
        	cout << endl;
		}
        cout << "\nEnter your option: ";
        cin >> op;
        if (op == 0){
        	break;
		}
		else if (op == 1){
			t = Create2(3, Create2(2, Create2(6, NULL, NULL), Create2(1, NULL, NULL)),
					 Create2(4, Create2(5, NULL, NULL), NULL));
			Operated = true;
		}
		else if (op == 2){
			if (isEmpty(t) == true){
				cout << "\nThe tree is Empty!" << endl;
				system("pause");
			}
			else{
				cout << "\nThe tree is not Empty!" << endl;
				system("pause");
			}
		}
		else if (op == 3){
			cout << "\n\t\tPrint Node\n\n";
			cout << "\t\tPress 1: InOrder -  LNR\n";
			cout << "\t\tPress 2: PostOrder -  LRN\n";
			cout << "\t\tPress 3: PreOrder -  NLR\n";
			
			cout << "Enter your choice: ";
			int x;
			cin >> x;
			if (x == 1){
				cout << "\nPrint InOrder:   ";
				NLR(t);
			}
			else if (x == 2){
				cout << "\nPrint PostOrder:   ";
				LRN(t);
			}
			else if (x == 3){
				cout << "\nPrint PreOrder:   ";
				NLR(t);
			}
			cout << endl;
			system("pause");
		}
		else if (op == 4){
			int x;
			cout << "\nEnter your node's data: ";
			cin >> x;
			if (SearchNode(x, t)){
				cout << "\nYes\n";
			}
			else{
				cout << "\nNo\n";
			}
			system("pause");
		}
		else if (op == 5){
			cout << "\n\t\tCheck for same parrent\n\n";
			int n, m;
			cout << "\nEnter the first Node: ";
			cin >> n;
			cout << "\nEnter the second Node: ";
			cin >> m;
			
			if (BT8a(n, m, t)){
				cout << "Those two have the same parrent!" << endl;
			}
			else{
				cout << "Those two do not the same parrent!" << endl;
			}
			system("pause");
		}
		else if (op ==6){
			cout << "\n\t\tCheck ancestor\n\n";
			int n, m;
			cout << "\nEnter Ancestor Node: ";
			cin >> n;
			cout << "\nEnter Child Node: ";
			cin >> m;
			if (BT8b(n, m, t)){
				cout << n << " is the ancestor of " << m << endl;
			}
			else{
				cout << n << " is not the ancestor of " << m << endl;
			}
			system("pause");
		}
	}
}

int main(){
	Tree t;
	MakeNull(t);
	DoFunction(t);
}
