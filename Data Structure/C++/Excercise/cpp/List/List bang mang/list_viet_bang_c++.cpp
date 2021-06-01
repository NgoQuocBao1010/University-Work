#include <iostream>

using namespace std;

#define MAXLENGTH 107

typedef int Position;

typedef int ElementType;

typedef struct {
	ElementType Elements[MAXLENGTH];
	int Last;
}List;

void MAKE_NULL(List &L){
	L.Last = 0;
}

void INSERT_LIST(ElementType x, Position p, List &L ){
	if (L.Last == MAXLENGTH) cout << "Danh sach da day"<< endl;
	else	if (p < 1 || p > L.Last + 1)
				cout << "Vi tri khong hop le" ;
			else {
				for (int i = L.Last; i > p - 1; --i )
					L.Elements[i] = L.Elements[i-1];
				L.Elements[p - 1] = x;
				++L.Last;
			}
}

void READ_LIST(List &L){
	cout << "Nhap so phan tu cua danh sach: " ;
	int n, x;
	cin >> n;
	
	for (int i = 1; i <= n; i++ ){
		cout << "Phan tu thu "<< i <<" la: " ;
		cin >> x;
		L.Elements[i - 1] = x;
		INSERT_LIST(x, i, L);
	}
}

void PRINT_LIST(List L){
	cout << "\nDanh sach : ";
	
	if (L.Last == 0) cout<< "[Danh sach rong]";
	for (int i=0; i < L.Last; i++){
		cout << L.Elements[i] << " " ;
	}
}

void SORT_LIST(List &L){
	int temp;
	for (int i = 0; i < L.Last; ++i){
		for (int j = i + 1; j < L.Last; ++j ){
			cout<<L.Elements[i];
			cout<<L.Elements[j];
			if ( L.Elements[i] > L.Elements[j]){
				temp = L.Elements[i];
				L.Elements[i] = L.Elements[j];
				L.Elements[j] = temp;
			}
		}
	}
}

void BT4(ElementType x, List &L){
	if (x >= L.Elements[L.Last - 1]) INSERT_LIST(x, L.Last + 1, L);
	else {
		for (int i = 0; i < L.Last; ++i){
			if (x <= L.Elements[i] ){
			INSERT_LIST(x, i + 1, L);
			break;
			}
		}
	}
}

void DELETE(Position p, List &L){
	if (p < 1 || p >= L.Last + 1) cout << "Vi tri nhu lon";
	else {
		for (int i = p; i <= L.Last; ++i ){
			L.Elements[i - 1] = L.Elements[i];
		}
		L.Last--;
	}
}
Position ENDLIST(List L){
	return L.Last;
}

Position LOCATE(ElementType x, List L){
	for (int i = 0; i < L.Last; ++i){
		if (x == L.Elements[i]) return i + 1;
	}
	return ENDLIST(L);
}

void BT6(List &L){
	List L1;
	MAKE_NULL (L1);
	READ_LIST(L1);
	
	for (int i = 0; i < L1.Last; ++i){
		BT4( L1.Elements[i], L);	
	}
}

void BT7(List &L){
	for (int i = 0; i < L.Last; ++i){
		for (int j = i + 1; j < L.Last; ++j) {
			if ( L.Elements[i] == L.Elements[j] ) DELETE(j + 1, L);
		}
	}
}

void BT8(List &L){
	List L1;
	MAKE_NULL(L1);
	READ_LIST(L1);
	
	for ( int i = 0; i < L1.Last; i++){
		if (LOCATE(L1.Elements[i], L) == ENDLIST(L))
		BT4(L1.Elements[i], L);
	}
}

void BT9(List &L){
	List L1, L2;
	MAKE_NULL(L1);
	MAKE_NULL(L2);
	READ_LIST(L1);
	READ_LIST(L2);
	
	
	for (int i = 0; i < L1.Last; ++i){
		INSERT_LIST(L1.Elements[i], i + 1, L);
	}
	
	for (int i = 0; i < L2.Last; ++i){
		BT4(L2.Elements[i], L);
	}
}

void BT10(List &L){
	for (int i = 0; i < L.Last; ++i){
		if (L.Elements[i] % 2 != 0) {
			DELETE(i + 1, L);
			--i;
		}
	}
}

void BT11(List &L, List &L1){
	int j=0;
	
	for (int i = 0; i < L.Last; ++i){
		if( L.Elements[i] % 2 == 0 ){
			j++;
			INSERT_LIST(L.Elements[i], j, L1);
		}
	}
	
	for (int i = 0; i < L.Last; ++i){
		if( L.Elements[i] % 2 == 0 ){
			DELETE( i + 1, L);
			--i;
		}
	}
}

int main(){
	List L, L1;
	MAKE_NULL(L);
	MAKE_NULL(L1);
	READ_LIST(L);


	SORT_LIST(L);
	PRINT_LIST(L);
	PRINT_LIST(L1);

}
