#include <iostream>
using namespace std;

struct NODE{
    int Data;
    struct NODE *pNext;
};

typedef struct NODE Node;

typedef struct{
    Node* Top;
}Stack;

void MakeNull(Stack &s){
    s.Top = NULL;
}

Node* GetNode(int x){
    Node* p = new Node;

    if (p == NULL){
        cout << "\nDanh sach rong!!";
        return p;
    }

    p->Data = x;
    p->pNext = NULL;
    return p;
}

bool isEmpty(Stack s){
    if (s.Top == NULL){
        return true;
    }
    return false;
}

void Push(int x, Stack &s){
    Node* p = GetNode(x);

    if (isEmpty(s) == true){
        s.Top = p;
    }

    else{
        p->pNext = s.Top;
        s.Top = p;
    }
}

void Pop(int &x, Stack &s){
    if (isEmpty(s) == true){
        cout << "\nDanh sach rong";
        return;
    }
    else{
        Node* p = s.Top;
        x = p->Data;
        s.Top = s.Top->pNext;
        delete p;
    }
}

void Top(int &x, Stack s){
    if (isEmpty(s) == true){
        cout << "\nDanh sach rong";
        return;
    }
    else{
        x = s.Top->Data;
        return;
    }
}

void OutPut(Stack &s){
    while (isEmpty(s) == false){
        int x;
        Pop(x, s);
        cout << x << "  ";
    }
    cout << "\nDanh sach da rong!!\n";
}

void DoFunction(Stack &s){

    while (true){
        system("cls");
        cout <<"\t\t=========Menu==========";
        cout <<"\n\t\t1. Them phan tu vao Stack - Push";
        cout <<"\n\t\t2. Lay phan tu dau tien ra khoi Stack - Pop";
        cout <<"\n\t\t3. Xem phan tu dau tien trong Stack - Top";
        cout <<"\n\t\t4. Lay ra tat ca phan tu trong Stack - OutPut";
        cout <<"\n\t\t0. Ket thuc";
        cout <<"\n\t\t=========End==========";
        int op;
        cout <<"\nNhap vao lua chon cua ban: ";
        cin >> op;
        if (op == 1){
            int x;
            cout << "\nNhap phan tu ban muon them: ";
            cin >> x;
            Push(x, s);
        }
        else if (op == 2){
            int x;
            Pop(x, s);
            cout << "\nPhan tu dau tien trong Stack: " << x << endl;
            system("pause");
        }
        else if (op == 3){
            int x;
            Top(x, s);
            cout << "\nPhan tu dau tien trong Stack: " << x << endl;
            system("pause");
        }
        else if (op == 4){
            cout << "\nDanh sach la: ";
            OutPut(s);
            system("pause");
        }
        else{
        	break;
		}
    }
}

int main(){
    Stack s;
    MakeNull(s);
    DoFunction(s);
}

