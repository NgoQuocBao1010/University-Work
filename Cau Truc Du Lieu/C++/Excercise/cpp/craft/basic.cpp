#include <iostream>
#include <cstdlib>

using namespace std;

void greeting();
int sum(int a = 3, int b = 10){
	int result = a + b;
	return result;
}
double sum(double a, double b = 10.0){
	double sum = a + b;
	return sum;
}
class myClass{
	public:
		void getdata(int x){
			data = x;
		}
	private:
		int data;
};

int main(){
	int x;
	int *p = NULL;
	
	myClass cl;
	
	cl.getdata(15);
	
	
}

void greeting(){
	printf("Xin Chao");
}
