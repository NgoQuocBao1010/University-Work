#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define B 11
#define Deleted "++++++++++"
#define Empty "**********"

typedef string ElementType;
typedef ElementType Dictionary[B];


void MakeNull(Dictionary &d){
	for (int i = 0; i < B; i ++){
		d[i]=Empty;
	}
}


int h(ElementType x){
	int i, sum = 0;
	
	for (int i=0; i < x.size(); i++){
		sum += x[i];
	}
	return sum % B;
}


int Locate(ElementType x, Dictionary &d){
	int i, initial;
	initial = h(x);
	i = 0;
	while ((i < B) && (d[(initial + i) % B] != Empty) && (d[(initial + i) % B] != x)){
		i ++;
	}
	return (initial + i) % B;
}


bool Member(ElementType x, Dictionary &d){
	return d[Locate(x, d)] == x;
}


void InsertSet(ElementType x, Dictionary& d){
	int bucket;
	
	if (!Member(x, d)){
		bucket = Locate(x, d);
		d[bucket] = x;
	}
	else{
		cout << "\nDeo hieu";
	}
}


void DeleteSet(ElementType x, Dictionary &d){
	int bucket;
	bucket = Locate(x, d);
	if (d[bucket] == x){
		d[bucket] = Deleted;
		return;
	}
}


void DoFunction(){
	Dictionary d;
	MakeNull(d);
	bool Operated = false;
	while (true){
		system("cls");
        cout <<"\t\t=========Menu==========";
        cout <<"\n\tPress  1: Create a Hash Table";
        cout <<"\n\tPress  2: Insert to Table";
        cout <<"\n\tPress  3: Delete from Table";
        cout <<"\n\tPress  4: Check if exist in Table";
        cout <<"\n\tPress  0: End the program!";
        cout <<"\n\t\t=========End==========";
        int op;
        if (Operated == true){
        	cout << "\nBang bam: \n";
			for (int i = 0; i < B; i ++){
				cout << d[i] << "\t";
			}
			cout << endl;
			system("pause");
		}
        cout << "\nEnter your option: ";
        cin >> op;
        if (op == 0){
        	break;
		}
		else if (op == 1){
			int n;
			ElementType c;
			
			cout << "\nNhap so phan tu ban muon them: ";
			cin >> n;
			
			for (int i = 0; i < n; i++){
				cout << "\nNhap vao phan tu: ";
				cin >> c;
				InsertSet(c, d);
			}
			Operated = true;
		}
		else if (op == 2){
			cout << "\nNhap phan tu ban muon them: ";
			ElementType x;
			cin >> x;
			InsertSet(x, d);
		}
		else if (op == 3){
			cout << "\nNhap phan tu ban muon xoa: ";
			ElementType x;
			cin >> x;
			DeleteSet(x, d);
		}
		else if (op == 4){
			cout << "\nNhap phan tu ban muon kiem tra: ";
			ElementType x;
			cin >> x;
			if (Member(x, d)){
				cout << "\nPhan tu " << x << " co ton tai trong bang.\n";
			}
			else{
				cout << "\nPhan tu " << x << " khong ton tai trong bang.\n";
			}
			system("pause");
		}
	}
}


int main(){
	DoFunction();
	
	return 0;
}


