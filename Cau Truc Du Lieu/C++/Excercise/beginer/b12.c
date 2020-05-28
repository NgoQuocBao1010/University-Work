#include <stdio.h>
#include <conio.h>
#define MaxLength 107


typedef int Position;


typedef struct {
	int tuso;
	int mauso;
}fraction;

typedef fraction ElementType;

typedef struct{
	ElementType Elements[MaxLength];
	int Last;
}List;

int FRAC(fraction *x){
	scanf("%d%d", &(*x).tuso, &(*x).mauso);
	
	if ((*x).mauso == 0) {
		printf("Phan tu nay khong hop le!\n");
		return 0;
	}
}

void INSERT_LIST(ElementType x, Position p, List *L){
	
	if ((*L).Last == MaxLength)
		printf("Danh sach day roi!\n");
	
	else if (p < 1 || p > (*L).Last + 1)
			printf("Vi tri khong Hop le\n");
		else {
			Position i;
			
			for (i = (*L).Last; i > p - 1; i--){
				(*L).Elements[i].tuso = (*L).Elements[i-1].tuso;
				(*L).Elements[i].mauso = (*L).Elements[i-1].mauso;
			}
			(*L).Elements[p - 1].tuso = x.tuso;
			(*L).Elements[p - 1].mauso = x.mauso;
			
			(*L).Last++;
		}
}

void MAKE_NULL(List *L){
	(*L).Last = 0;
}

void READ_LIST(List *L){
	int i, n;
	fraction x;
	printf("Nhap so phan tu cua danh sach: ");
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++){
		printf("Nhap tu so va mau so cua phan tu thu %d: ", i);
		if (FRAC(&x) == 0){
			i --;
		}
		else INSERT_LIST(x, i, L);
		
	}
}

void PRINT_LIST(List L){
	int i;
	printf("Danh sach cac phan tu la: ");
	for (i=0; i < L.Last; i++){
		printf("%d/%d ", L.Elements[i].tuso, L.Elements[i].mauso);
	}
}


void DELETE_LIST(Position p, List *L){
	if ((p<1) || (p>(*L).Last))
		printf("Vi tri khong hop le");
	else {
		Position i;
		for (i = p - 1; i < (*L).Last - 1; i ++){
			(*L).Elements[i].tuso = (*L).Elements[i + 1].tuso;
			(*L).Elements[i].mauso = (*L).Elements[i + 1].mauso;
	}
		(*L).Last--;
	}
}

void RutGon(fraction *x){
	int uc;
	uc = UCLN((*x).tuso, (*x).mauso);
	(*x).tuso = (*x).tuso / uc;
	(*x).mauso = (*x).mauso / uc;
}

fraction Tich2phanso(fraction a, fraction b){
	
	RutGon(&a);
	RutGon(&b);
	
	fraction z;
	
	z.tuso = a.tuso * b.tuso;
	z.mauso	= a.mauso * b.mauso;
	
	RutGon(&z);
	
	return z;
}

void PRINT_FRAC(fraction x){
	printf("%d/%d\n", x.tuso, x.mauso);
}

void BT12e(List *L){
	Position i;
	
	for (i = 1; i <= (*L).Last; i++){
		if ( (*L).Elements[i-1].tuso > (*L).Elements[i - 1].mauso ) DELETE_LIST(i, L);
	}
}



//them 1 phan tu vao dau danh sach
void BT12b(List *L){
	fraction x;
	printf("Nhap phan so can them vao vi tri dau: \n");
	if (FRAC(&x) == 0) return BT12b(L);
	
	else INSERT_LIST(x, 1, L);
	
}






// tim uoc chung lon nhat
int UCLN(int a, int b){
	int i, hi;
	if (a > b){
		for (i = b; i >= 1; i --){
			if (a % i == 0 && b % i == 0 ) return i;
		}
	}
	else if (a < b){
		for (i = a; i >= 1; i --){
			if (a % i == 0 && b % i == 0 ) return i;
		}
	}
		else return a;
}


// toi gian cac phan so trong danh sach
void BT12d(List *L){
	int i, uc;
	
	for (i = 0; i < (*L).Last; i++){
		uc = UCLN((*L).Elements[i].tuso, (*L).Elements[i].mauso);
		(*L).Elements[i].tuso = (*L).Elements[i].tuso / uc;
		(*L).Elements[i].mauso = (*L).Elements[i].mauso / uc;
	}
}

void BT12f(List *L){
	int i, j;
	fraction *f1, *f2;
	fraction z;
	for (i= 0; i < (*L).Last; i++){
		for (j= i + 1; j < (*L).Last; j++){
			z = Tich2phanso((*L).Elements[i], (*L).Elements[j]);
			if (z.mauso == z.tuso){
				f1 = &(*L).Elements[i];
				f2 = &(*L).Elements[j];
			}
		}
	}
	PRINT_FRAC(*f1);
	PRINT_FRAC(*f2);
}


void BT12ff(fraction *f1, fraction *f2, List *L){
	int i, j;
	fraction z;
	for (i= 0; i < (*L).Last; i++){
		for (j= i + 1; j < (*L).Last; j++){
			z = Tich2phanso((*L).Elements[i], (*L).Elements[j]);
			if (z.mauso == z.tuso){
				f1 = &(*L).Elements[i];
				f2 = &(*L).Elements[j];
			}
		}
	}
	PRINT_FRAC(*f1);
	PRINT_FRAC(*f2);
}


int main(){
	List L;

	MAKE_NULL(&L);
	
	READ_LIST(&L);
	
	BT12f(&L);
	
	PRINT_LIST(L);
	
	return 0;
}
