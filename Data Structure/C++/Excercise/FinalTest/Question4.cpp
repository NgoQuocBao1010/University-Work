#include <iostream>

using namespace std;

#define B 11
#define empty -1000000007
#define deleted 1000000007


typedef int ElementType;
typedef ElementType Dictionary[B];


void MakeNull(Dictionary &d){
	for (int i = 0; i < B; i ++){
		d[i] = empty;
	}
}


int h(ElementType x){
	return (x * x) % B;	
}


int Locate(ElementType x, Dictionary &d){
	int i, initial;
	initial = h(x);
	i = 0;
	
	while ((i < B) && (d[(initial + i * i) % B] != empty) && (d[(initial + i * i) % B] != x) ){
		++i;
	}
	return (initial + i * i) % B;
}


int Locate1(ElementType x, Dictionary &d){
	int i, initial;
	initial = h(x);
	i = 0;

	while ((i < B) && (d[(initial + i * i) % B] != empty) && (d[(initial + i * i) % B] != x) && (d[(initial + i*i) % B] != deleted)){
		i++;
	}
	return (initial + i*i) % B;
}


bool Member(ElementType x, Dictionary &d){
	return d[Locate(x, d)] == x;
}


void Insert_set(ElementType x, Dictionary &d){
	int bucket;
	
	if (!Member(x, d)){
		bucket = Locate1(x, d);
		if (d[bucket] == empty || d[bucket] == deleted)
			d[bucket] = x; 
	}
	else{
		cout << "\nOut of space, moderfker\n";
		system("pause");
	}
}


void Delete_set(ElementType x, Dictionary &d){
	int bucket;
	
	if (Member(x, d)){
		bucket = Locate(x, d);
		d[bucket] = deleted;
	}
}


void Output_dict(Dictionary d){
	system("cls");
	cout << "\n\n\tBang bam: \n";
	for (int i=0; i < B; ++i){
		cout << d[i] << endl;
	}
	system("pause");
}


void DoFunction(){
	Dictionary d;
	MakeNull(d);
	while (true){
		system("cls");
        cout <<"\t\t=========Menu==========";
        cout <<"\n\tPress  1: Cau4a - Lam trong giay";
        cout <<"\n\tPress  2: Cau4b - Create a Hash Table";
        // 1, 5, 6, 10, 4, 7, 8, 3, 2, 0
        cout <<"\n\tPress  3: Cau4c - Delete from Table";
        cout <<"\n\tPress  4: Print Table";
        cout <<"\n\tPress  0: End the program!";
        cout <<"\n\t\t=========End==========";
        int op;
        cout << "\nEnter your option: ";
        cin >> op;
        if (op == 0){
        	break;
		}
		else if (op == 1){
			cout << "\n\t\tLAM TRONG GIAY!!!!\n\n";
			system("pause");
		}
		else if (op == 2){
			int n;
			ElementType c;
			
			cout << "\nNhap so phan tu ban muon them: ";
			cin >> n;
			
			for (int i = 0; i < n; i++){
				cout << "\nNhap vao phan tu: ";
				cin >> c;
				Insert_set(c, d);
			}
		}
		else if (op == 3){
			cout << "\nNhap phan tu ban muon xoa: ";
			ElementType x;
			cin >> x;
			Delete_set(x, d);
		}
		else if (op == 4){
			Output_dict(d);
		}
	}
}


int main(){
	DoFunction();
	return 0;
}
