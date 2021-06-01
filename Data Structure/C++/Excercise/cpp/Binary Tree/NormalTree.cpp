#include <iostream>
#define Maxlength 11
using namespace std;

typedef char DataType;
typedef int Node;
typedef struct{
	DataType Data[Maxlength];
	Node Parent[Maxlength];
	int MaxNode;
}Tree;

void MakeNull(Tree &t){
	t.MaxNode = 0;
}

bool EmptyTree(Tree &t){
	return (t.MaxNode == 0);
}

// xac dinh cha cua nut n
Node Parent(Node n, Tree t){
//	if (EmptyTree(t) || n > t.MaxNode - 1 || n < 0){
//		return -1;
//	}
	return t.Parent[n];
}

//xac dinh con trai nhat
Node LMC(Node n, Tree t){
//	if (EmptyTree(t) || n > t.MaxNode - 1 || n < 0){
//		return -1;
//	}
	
	for (int i = n + 1; i < t.MaxNode; ++i){
		if (t.Parent[i] == n)
			return i;
	}
	return -1;
}

//xac dinh chi em ruot phai
Node RSL(Node n, Tree t){
//	if (EmptyTree(t) || n > t.MaxNode - 1 || n < 0){
//		return -1;
//	}
	
	Node p = Parent(n, t);
	for (int i = n + 1; i < t.MaxNode; ++i){
		if (p == Parent(i, t))
			return i;
	}
	return -1;
}

// 
DataType Label(Node n, Tree t){
	if (EmptyTree(t) || n > t.MaxNode - 1 || n < 0){
		return -1;
	}
	
	return t.Data[n];
}

// cac thu tuc duyet
void PreOrder(Node n, Tree t){
	char c = Label(n, t);
	cout << c;
	Node i = LMC(n, t);
	while (i != -1){
		PreOrder(i, t);
		i = RSL(i, t);
	}
}

void PostOrder(Node n, Tree t){
	Node i = LMC(n, t);
	
	while (i != -1){
		PostOrder(i, t);
		i = RSL(n, t);
	}
	char c = Label(n, t);
	cout << c << "   ";
}

void InOrder(Node n, Tree t){
	Node i = LMC(n, t);
	if (i != -1){
		InOrder(i, t);
	}
	char c = Label(n, t);
	cout << c << "   ";
	while (i != -1){
		InOrder(i, t);
		i = RSL(n, t);
	}
}

Node Root(Tree t){
	if (!EmptyTree(t))
		return 0;
	return -1;
}

void ReadTree(Tree &t){
	MakeNull(t);
	cout << "\nSo nut cua cay la: ";
	cin >> t.MaxNode;
	
	cout << "\nNhap nhan cua nut goc: ";
	cin >> t.Data[0];
	
	t.Parent[0] = -1;
	
	for (int i = 1; i < t.MaxNode; ++i){
		cout << "\nNhap cha cua nut " << i << " : ";
		cin >> t.Parent[i];
		
		cout << "\nNhap nhan cua nut: ";
		cin >> t.Data;
	}
}

int main(){
	Tree t;
	ReadTree(t);
	PreOrder(Root(t), t);
	return 0;
}
