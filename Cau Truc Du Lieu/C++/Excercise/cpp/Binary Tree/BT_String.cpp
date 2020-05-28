#include <iostream>
#include <string.h>
using namespace std;

struct NODE{
	string Data;
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

void InsertTree(string s, Tree &t){
	if (t == NULL){
		Node* p = new Node;
		p->Data = s;
		p->left = p->right = NULL;
		t = p;
	}
	else{
		if (s.compare(t->Data) == 1){
			InsertTree(s, t->right);
		}
		else if (s.compare(t->Data) == -1){
			InsertTree(s, t->left);
		}		
	}
}

bool SearchNode(string s, Tree t){
	if (isEmpty(t)){
		return false;
	}
	if (s.compare(t->Data) == -1){
		return SearchNode(s, t->left);
	}	
	else if (s.compare(t->Data) == 1){
		return SearchNode(s, t->right);
	}
	else if (s.compare(t->Data) == 0){
		return true;
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

void DeleteNode(string s, Tree &t){
	if (isEmpty(t)){
		return;
	}
	
	if (s.compare(t->Data) == 1){
		DeleteNode(s, t->right);
	}
	else if (s.compare(t->Data) == -1){
		DeleteNode(s, t->left);
	}
	else if (s.compare(t->Data) == 0){
		Node *p = t;
		
		if (t->left == NULL){
			t = t->right;
		}
		else if (t->right == NULL){
			t = t->left;
		}
		else{
			RightMostLeft(p, t->left);
		}
		delete p;
	}
}

void BT13(string city, Tree &t){
	if (SearchNode(city, t) == true){
		cout << "\t" << t->Data;
		if (city.compare(t->Data) == 0){
			return;
		}
		else if (city.compare(t->Data) == 1){
			BT13(city, t->right);
		}
		else if (city.compare(t->Data) == -1){
			BT13(city, t->left);
		}
	}
	
	return;
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
        cout <<"\n\tPress  1: Insert data into the tree - InsertTree";
        cout <<"\n\tPress  2: Check whether the tree is Empty - isEmpty";
        cout <<"\n\tPress  3: Search a Node in Tree - SearchNode";
        cout <<"\n\tPress  4: (BT13) Find the path to 'DONGTHAP' ";
        cout <<"\n\tPress  5: Find the path to the given city ";
        cout <<"\n\tPress  6: Delete Node";
        cout <<"\n\tPress  7: Print Node";
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
			string s;
			cout << "Enter your data: ";
			cin >> s;
			InsertTree(s, t);
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
			cout << "\n\t\tSearch for the node in Tree\n\n";
			string s;
			cout<< "Enter your node's data: ";
			cin >> s;
			SearchNode(s, t);
			if (SearchNode(s, t) == true){
				cout << "\nYour node does exist in the tree"<<endl;
			}
			else{
				cout << "\nYour node does not exist in the tree"<<endl;
			}
			system("pause");
			Operated = true;
		}
		else if (op == 4){
			cout << "\n\t\tFind the path to DONGTHAP\n\n";
			cout << "Duong di toi DONGTHAP:" << endl;
			string s;
			s = "DONGTHAP";
			BT13(s, t);
			cout << "\n";
			system("pause");
			Operated = true;
		}
		else if (op == 5){
			cout << "\n\t\tFInd the path to the given city\n\n";
			cout << "Enter the city you want: ";
			string s;
			cin >> s;
			BT13(s, t);
			cout << "\n";
			system("pause");
			Operated = true;
		}
		else if (op == 6){
			cout << "\n\t\tDelete Node\n\n";
			cout << "\nEnter Node's data: ";
			string s;
			cin >> s;
			DeleteNode(s, t);
			Operated = true;
		}
		else if (op == 7){
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
			system("pause");
		}
	}
}

int main(){
	Tree t;
	MakeNull(t);
	DoFunction(t);
}
