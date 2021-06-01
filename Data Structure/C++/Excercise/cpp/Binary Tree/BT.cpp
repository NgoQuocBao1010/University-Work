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
	if (t == NULL){
		return true;
	}
	return false;
}

void InsertTree(Tree &t, int x){
	if (t == NULL){
		Node* p = new Node;
		p->Data = x;
		p->left = p->right = NULL;
		t = p;
	}
	
	else{
		if (t->Data < x){
			InsertTree(t->right, x);
		}
		else if (t->Data > x){
			InsertTree(t->left, x);
		}
	}
}

bool SearchNode(Tree t, int x){
	if (isEmpty(t) == true){
		return false;
	}
	
	if (t->Data > x){
		SearchNode(t->left, x);
	}
	else if (t->Data < x){
		SearchNode(t->right, x);
	}
	else{
		return true;
	}
}

int CountNode(Tree t){
	if (isEmpty(t) == true){
		return 0;
	}
	else{
		return 1 + CountNode(t->left) + CountNode(t->right);
	}
	
}

bool isLeaf(int x, Tree t){
	if (isEmpty(t) == true){
		return false;
	}
	else{
		if (t->Data > x ){
			isLeaf(x, t->left);
		}
		else if(t->Data < x){
			isLeaf(x, t->right);
		}
		else{
			if (t->left == NULL && t->right == NULL){
				return true;
			}
			return false;
		}
	}
}


bool HaveOneChild(int x, Tree t){
	if (isEmpty(t) == true){
		return false;
	}
	else{
		if (t->Data > x ){
			HaveOneChild(x, t->left);
		}
		else if(t->Data < x){
			HaveOneChild(x, t->right);
		}
		else{
			if (t->left == NULL && t->right == NULL){
				return false;
			}
			else if (t->left != NULL && t->right != NULL){
				return false;
			}
			return true;
		}
	}
}

void SwapValue(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void LeftMostRight(Tree &p, Tree &q){
	if (q->left != NULL){
		LeftMostRight(p, q->left);
	}
	else{
		p->Data = q->Data;
		p = q;
		q = q->right;
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

void DeleteNode(int x, Tree &t){
	if (isEmpty(t) == true){
		return;
	}	
	
	if (t->Data > x){
		DeleteNode(x, t->left);
	}
	else if (t->Data < x){
		DeleteNode(x, t->right);
	}
	else{
		Node *p = t;
		
		if (t->right == NULL){
			t = t->left;
		}
		
		else if (t->left == NULL){
			t = t->right;
		}
		else{
			RightMostLeft(p, t->left);
			
		}
		delete p;
	}
}

/*
bool Bt8a(int n, int m, Tree t){
	if (SearchNode(t, n) == false || SearchNode(t, m) == false || m == n){
		return false;
	}
	if (t == NULL){
		return false;
	}
	if (t->left->Data == n && t->right->Data == m ){
		return true;
	}
	if (Bt8a(n, m, t->left) == true){
		return true;
	}
	if (Bt8a(n, m, t->right) == true){
		return true;
	}
	return false;
}
*/

bool Bt8a(int n, int m, Tree t){
	if (SearchNode(t, n) == false || SearchNode(t, m) == false || m == n){
		return false;
	}
	if (t == NULL || t->Data == n || t->Data == m){
		return false;
	}
	else if (t->left->Data == n && t->right->Data == m){
		return true;
	}
	else{
		if (t->Data < n){
			return Bt8a(n, m, t->right);
		}
		else if (t->Data > n){
			return Bt8a(n, m, t->left);
		}
	}
}

bool Bt8b(int n, int m, Tree t){
	if (SearchNode(t, n) == false || SearchNode(t, m) == false || m == n){
		return false;
	}
	if (t->Data > n){
		Bt8b(n ,m , t->left);
	}
	else if (t->Data < n){
		Bt8b(n, m, t->right);
	}
	else{
		Node* p = t;
		if (SearchNode(p, m)){
			return true;
		}
		else{
			return false;
		}
	}
}

int Bt8c(Tree t){
	if (t == NULL){
		return 0;
	}
	else if (HaveOneChild(t->Data, t)){
		return 1 + Bt8c(t->left) + Bt8c(t->right);
	}
	else if (HaveOneChild(t->Data, t) == false){
		return 0 + Bt8c(t->left) + Bt8c(t->right);
	}
}

int Bt8d(Tree t){
	if (t == NULL){
		return 0;
	}
	else if (isLeaf(t->Data, t)){
		return 1 + Bt8d(t->left) + Bt8d(t->right);
	}
	else if (isLeaf(t->Data, t) == false){
		return 0 + Bt8d(t->left) + Bt8d(t->right);
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

void DoFunction(Tree &t){
	bool Operated = false;
	while (true){
		system("cls");
        cout <<"\t\t=========Menu==========";
        cout <<"\n\tPress  1: Insert data into the tree - InsertTree";
        cout <<"\n\tPress  2: Check whether the tree is Empty - isEmpty";
        cout <<"\n\tPress  3: Print from Left to Node to Right - LNR";
        cout <<"\n\tPress  4: Search a Node in Tree - SearchNode";
        cout <<"\n\tPress  5: Count the nodes in Tree - CountNode";
        cout <<"\n\tPress  6: Check whether node is a leaf - isLeaf ";
        cout <<"\n\tPress  7: Check whether node has one child - HaveOneChild ";
        cout <<"\n\tPress  8: Delete Node - DeleteNode";
        cout <<"\n\tPress  9: Print Tree ";
        cout <<"\n\tPress 10: (BT8a) Check for same parrent ";
        cout <<"\n\tPress 11: (BT8b) Check ancestor ";
        cout <<"\n\tPress 12: (BT8c) Count the Nodes have one child ";
        cout <<"\n\tPress 13: (BT8d) Count the leaf-Node ";
        cout <<"\n\tPress  0: End the program!";
        cout <<"\n\t\t=========End==========";
        int op;
        if (Operated == true){
        	cout << "\n\tMY BINARY TREE (NLR)\n   ";
        	NLR(t);
        	cout << endl;
		}
        cout << "\nEnter your option: ";
        cin >> op;
        if (op == 0){
        	break;
		}
		else if (op == 1){
			cout << "\n\t\tInsert data into the tree\n\n";
			int x;
			cout << "Enter your data: ";
			cin >> x;
			InsertTree(t, x);
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
			cout << "\n\t\t\tMY BINARY TREE\n";
			LNR(t);
			cout <<"\n";
			system("pause");
		}
		else if (op == 4){
			cout << "\n\t\tFind data in the tree\n\n";
			int x;
			cout << "\nEnter the data: ";
			cin >> x;
			SearchNode(t, x);
			if (SearchNode(t, x) == true){
				cout << "\n" << x << " does exist in Tree." << endl; 
			}
			else{
				cout << "\n" << x << " does not exist in Tree." << endl; 
			}
			system("pause");
		}
		else if (op == 5){
			cout << "\n\t\tCount the nodes in Tree\n\n";
			int x;
			x = CountNode(t);
			cout << "\nThere are " << x << " nodes in Tree." << endl;
			system("pause");
		}
		else if (op == 6){
			cout << "\n\t\tCheck for leaf-node\n\n";
			int x;
			cout << "\nEnter Node: ";
			cin >> x;
			if (isLeaf(x, t) == true){
				cout << "\nNode " << x << " is a leaf"<<endl;
			}
			else{
				cout << "\nNode " << x << " is not a leaf"<< endl;
			}
			system("pause");
		}
		else if (op == 7){
			cout << "\n\t\tCheck for OneChild-Node\n\n";
			int x;
			cout << "\nEnter Node: ";
			cin >> x;
			if ( HaveOneChild(x, t) == true){
				cout << "\nNode " << x << " has one child"<<endl;
			}
			else{
				cout << "\nNode " << x << " does not have one child"<< endl;
			}
			system("pause");
		}
		else if (op == 8){
			cout << "\n\t\tDelete a Node in Tree\n\n";
			int x;
			cout << "\nEnter Node's data: ";
			cin >> x;
			if (SearchNode(t, x)){
				DeleteNode(x , t);
			}
			else{
				cout << "\n" << x << " does not exist in Tree." << endl; 
				system("pause");
			}
		}
		else if (op == 9){
			cout << "\n\t\tPrint the tree\n";
			cout << "\n Press 1: Print from Node to Left to Right - NLR";
			cout << "\n Press 2: Print from Left to Node to Right - LNR";
			cout << "\n Press 3: Print from Node to Right to Node - LRN";
			int op1;
			cout << "\n\nEnter your option: ";
			cin >> op1;
			
			if (op1 == 1){
				system("cls");
				cout << "\n\t\t\tMY BINARY TREE\n";
				NLR(t);
				cout <<"\n";
				system("pause");
			}
			else if (op1 == 2){
				system("cls");
				cout << "\n\t\t\tMY BINARY TREE\n";
				LNR(t);
				cout <<"\n";
				system("pause");
			}
			else if (op1 == 3){
				system("cls");
				cout << "\n\t\t\tMY BINARY TREE\n";
				LRN(t);
				cout <<"\n";
				system("pause");
			}	
		}
		else if (op == 10){
			cout << "\n\t\tCheck for same parrent\n\n";
			int n, m;
			cout << "\nEnter the first Node: ";
			cin >> n;
			cout << "\nEnter the second Node: ";
			cin >> m;
			if (n > m){
				SwapValue(n, m);
			}
			
			if (Bt8a(n, m, t)){
				cout << "Those two have the same parrent!" << endl;
			}
			else{
				cout << "Those two do not the same parrent!" << endl;
			}
			system("pause");
		}
		else if (op == 11){
			cout << "\n\t\tCheck ancestor\n\n";
			int n, m;
			cout << "\nEnter Ancestor Node: ";
			cin >> n;
			cout << "\nEnter Child Node: ";
			cin >> m;
			if (Bt8b(n, m, t)){
				cout << n << " is the ancestor of " << m << endl;
			}
			else{
				cout << n << " is not the ancestor of " << m << endl;
			}
			system("pause");
		}
		else if (op == 12){
			cout << "\n\t\tCount the nodes have one child in Tree\n\n";
			int x;
			x = Bt8c(t);
			cout << "\nThere are " << x << " nodes in Tree." << endl;
			system("pause");
		}
		else if (op == 13){
			cout << "\n\t\tCount the leaf-nodes in Tree\n\n";
			int x;
			x = Bt8d(t);
			cout << "\nThere are " << x << " nodes in Tree." << endl;
			system("pause");
		}
	}
}
int main(){
	Tree t;
	MakeNull(t);
	DoFunction(t);
	
	return 0;
}
