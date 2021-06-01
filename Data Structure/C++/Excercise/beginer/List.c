#include <stdio.h>

#include <conio.h>

#define MaxLength 107



typedef int ElementType;

typedef int Position;

typedef struct{
	ElementType Elements[MaxLength];
	int Last  ;
}List;

void INSERT_LIST(ElementType X, Position P, List *L){
	if ((*L).Last==MaxLength) 
		printf("Danh sach day");	
	else 	if ((P<1) || (P>(*L).Last+1))
			printf("Vi tri khong hop le");
		 else{
			 Position Q;
	 		
			 for (Q=(*L).Last;Q>P-1;Q--)
				(*L).Elements[Q]=(*L).Elements[Q-1];
			
			 (*L).Elements[P-1]=X;
			
			 (*L).Last++;
		 }
}
void DELETE_LIST(Position P, List *L){
	if ((P<1) || (P>(*L).Last))
		printf("Vi tri khong hop le");
	else {
		 Position Q;
		 for(Q=P-1;Q<(*L).Last-1;Q++)
			 (*L).Elements[Q]=(*L).Elements[Q+1];
			 
		 (*L).Last--;
	}
}

Position ENDLIST(List *L){
	return (*L).Last + 1;
}

Position LOCATE(ElementType X, List *L){
	
	Position i;
	for (i=1; i <= (*L).Last; i++){
		if ((*L).Elements[i-1] == X) return i ;
	}
	return 0; 
}

ElementType RETRIEVE(Position p, List *L){
	return (*L).Elements[p];
}

Position NEXT(Position p, List *L){
	return p + 1;
}

Position PREVIOUS(Position p, List *L){
	return p - 1;
}

Position FIRST( List *L){
	return  1;
}

int EMPTY_LIST(List *L){
	return (*L).Last == 0;
}

void MAKE_NULL(List *L){
	(*L).Last = 0;
}

void READ_LIST(List *L){
	int n,x;
	printf("Nhap so phan tu cua danh sach : ");
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++){
		printf("nhap phan tu thu %d: ",i);
		scanf("%d",&x);
		INSERT_LIST(x, i, L);
	}
}

void PRINT_LIST(List L){
	printf("Danh sach cac phan tu la: ");
	int i;
	
	for (i = 0; i < L.Last; i++){
		printf("%d ", L.Elements[i]);
	}
}

void BT1a(List *L){
	int n,x;
	printf("So phan tu trong mang la: ");
	scanf("%d", &n);
	
	int i;
	for (i=1; i <= n; i++){
		printf("Phan tu thu %d: ", i);
		scanf("%d", &x);
		INSERT_LIST(x, i , L);
	}
}

// luu cac phan tu vao danh sach nhung nguoc lai
void BT1b(List *L){
	int n,x;
	printf("So phan tu trong mang la: ");
	scanf("%d", &n);
	
	int i;
	for (i=1; i <= n; i++){
		printf("Phan tu thu %d: ", i);
		scanf("%d", &x);
		INSERT_LIST(x, 1 , L);
	}
}

// sap xep lai danh sach
void BT1c(List *L){
	int i, j, decoy;
	
	for (i = 0; i <= (*L).Last - 1; i++){
		for (j = i +1; j < (*L).Last; j ++ ){
			if ((*L).Elements[i] > (*L).Elements[j]){
				decoy = (*L).Elements[i];
				(*L).Elements[i] = (*L).Elements[j];
				(*L).Elements[j] = decoy;
			}
			
		}
	}
}

// them vao phan tu 1 cach co thu tu
void BT4_cuatui(ElementType x ,List *L){
	
	int i;
	
	if (x >= (*L).Elements[(*L).Last - 1] )
		INSERT_LIST(x, (*L).Last + 1 , L);
	else {
		for (i = 0; i <= (*L).Last - 1; i ++){
			if (x <= (*L).Elements[i]){
				INSERT_LIST(x, i + 1, L);
				break;
			}
		}
	}
}

void BT4_cuaVinh(ElementType x, List *L){
	Position i;
	for (i = 1; i <= (*L).Last; i++){
		if ( RETRIEVE(i-1, L) >= x )
		INSERT_LIST(x, i + 1, L);
		return;
	}
	INSERT_LIST(x, (*L).Last + 1, L);
}


void BT5(ElementType x,List *L){
	Position n = LOCATE(x, L);
	DELETE_LIST( n, L);
}

// them 1 danh sach cac so nguyen khac vao 1 cach co thu tu
void BT6(List *L){
	List L1;
	MAKE_NULL(&L1);
	READ_LIST(&L1);
	int i;
	for (i = 0; i <= L1.Last - 1; i++){
		BT4_cuatui(L1.Elements[i], L);
	}
	
	
}

// loai bo cac ptu trung nhau
void BT7(List *L){
	int i;
	
	for (i =  (*L).Last; i > 0; i --){
		if ((*L).Elements[i] == (*L).Elements[i - 1])
		DELETE_LIST(i, L);
	}
}

// bo cac so le
void BT10(List *L) {
	int i;
    for ( i = 1; i <= (*L).Last; i++) {
        if ((*L).Elements[i-1] % 2 != 0)
			DELETE_LIST(i, L);
    }
}

//them 1 danh sach vao 1 cach co thu tu voi cac phan tu khong trung nhau
void BT8_dara(List *L){
	List L1;
	READ_LIST(&L1);
	
	int i;
	for (i=0; i <= L1.Last - 1; i++){
		if (LOCATE(L1.Elements[i], L) == 0){
			BT4_cuatui(L1.Elements[i], L);
		}
	}
}

void BT8(List *L){
	int x;
	
	scanf("%d", &x);
	
	if (LOCATE(x, L) == ENDLIST(L))
	BT4_cuatui(x, L);
}



// cong 2 dsach vao thanh 1 dsach
void BT9(List *L){
	List L1, L2;
	
	READ_LIST(&L1);
	READ_LIST(&L2);
	
	int i;
	
	for (i = 1; i <= L1.Last; i++){
		INSERT_LIST(L1.Elements[i-1],  i, L);
	}
	
	for (i = 0; i < L2.Last; i++){
		BT4_cuatui(L2.Elements[i], L);
	}
}


// chia 1 danh sach thanh 2 danh sach 
void BT11(List *L){
	List L1;
	int i;
	int j = 0;
	for (i = 1; i <= (*L).Last ; i++){
		if ((*L).Elements[i-1] % 2 == 0 ){
			j ++;
			INSERT_LIST((*L).Elements[i-1], j, &L1);
			}
	}
	for (i = 1; i <= (*L).Last ; i++){
		if ((*L).Elements[i-1] % 2 == 0 ){
			DELETE_LIST(i, L);
		}
	}
	PRINT_LIST(L1);
	printf("\n");
}



int main(){
	List L;
	MAKE_NULL(&L);
	
	READ_LIST(&L);
	BT8_dara(&L);
	PRINT_LIST(L);
}






