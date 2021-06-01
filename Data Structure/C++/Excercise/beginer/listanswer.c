#include<bits/stdc++.h>

#define MaxLength 107
#define oo 1000000007

using namespace std;

typedef int ElementType;

typedef int Position;

typedef struct{
    ElementType Elements[MaxLength];
    int Last = 0;
} List;

void INSERT_LIST(ElementType x, Position p, List &L) {
    if (L.Last == MaxLength) cout << "Danh sach day";
    else if (p < 1 || p > L.Last + 1) cout << "Vi tri khong hop le";
    else {
        for (Position i = L.Last; i >= p; --i) {
            L.Elements[i+1] = L.Elements[i];
        }
        L.Elements[p] = x;
        ++L.Last;
    }
}

Position ENDLIST(List &L){
    return L.Last + 1;
}

Position LOCATE(ElementType x, List &L){
    for (Position i = 1; i <= L.Last; ++i) if (L.Elements[i] == x) return i;
    return ENDLIST(L);
}

ElementType RETRIEVE(Position p, List &L){
    return L.Elements[p];
}

void DELETE_LIST(Position p, List &L){
    if (p < 1 || p > L.Last + 1) cout << "Vi tri khong hop le";
    else {
        for (int i = p; i < L.Last; ++i) L.Elements[i] = L.Elements[i+1];
        --L.Last;
    }
}

Position NEXT(Position p, List &L){
    return p + 1;
}

Position PREVIOUS(Position p, List &L){
    return p - 1;
}

Position FIRST(List &L){
    return 1;
}

int EMPTY_LIST(List &L){
    return L.Last == 0;
}

void MAKENULL_LIST(List &L){
    L.Last = 0;
}

void READ_LIST(List &L){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        INSERT_LIST(x, L.Last + 1, L);
    }
}

void PRINT_LIST(List &L){
    for (Position i = 1; i <= L.Last; ++i) cout << L.Elements[i] << " ";
    cout << endl;
}

/* -------------------BT------------------ */

void BT1a(){
    List L;
    READ_LIST(L);
    PRINT_LIST(L);
}

void BT1b(){
    List L;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        INSERT_LIST(x, 1, L);
    }
}

void BT3a(List &L){
    for (Position i = 1; i < L.Last; ++i) {
        for (Position j = i + 1; j <= L.Last; ++j) {
            if (RETRIEVE(i, L) > RETRIEVE(j, L)) swap(L.Elements[i], L.Elements[j]);
        }
    }
}

void BT1c(List &L){
    BT3a(L);
    PRINT_LIST(L);
}

void BT4(ElementType x, List &L){
    for (Position i = 1; i <= L.Last; ++i) {
        if (RETRIEVE(i, L) >= x){
            INSERT_LIST(x, i, L);
            return;
        }
    }
    INSERT_LIST(x, L.Last+1, L);
}

void BT5(ElementType x, List &L){
    DELETE_LIST(LOCATE(x, L), L);
}

void BT6(){
    int n; cin >> n;
    List L;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        BT4(x, L);
    }
    PRINT_LIST(L);
}

void BT7(List &L){
    int ck[MaxLength];
    memset(ck, 0, sizeof ck);
    for (Position i = 1; i <= L.Last;) {
        if (ck[RETRIEVE(i, L)]) DELETE_LIST(i, L);
        else {
            ck[RETRIEVE(i, L)] = 1;
            ++i;
        }
    }
}

void BT8(){
    int n; cin >> n;
    List L;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (LOCATE(x, L) == ENDLIST(L)) BT4(x, L);
    }
    PRINT_LIST(L);
}

void BT9(List &L, List &L1, List &L2){
    int i = 1, j = 1;
    INSERT_LIST(oo, L1.Last + 1, L1);
    INSERT_LIST(oo, L2.Last + 1, L2);
    while (i != L1.Last + 1 || j != L2.Last + 1) {
        if (L1.Elements[i] <= L2.Elements[j]){
            INSERT_LIST(L1.Elements[i], L.Last+1, L);
            ++i;
        }
        else {
            INSERT_LIST(L2.Elements[j], L.Last+1, L);
            ++j;
        }
    }
    DELETE_LIST(L.Last, L);
}

void BT10(List &L) {
    for (int i = 1; i <= L.Last; ++i) {
        if (L.Elements[i] % 2 != 0) DELETE_LIST(i, L);
    }
}

void BT11(List &L, List &L1, List &L2) {
    for (int i = 1; i <= L.Last; ++i) {
        if (L.Elements[i] % 2 == 0) INSERT_LIST(L.Elements[i], L1.Last+1, L1);
        else INSERT_LIST(L.Elements[i], L2.Last+1, L2);
    }
}

int main(){

    return 0;
}



