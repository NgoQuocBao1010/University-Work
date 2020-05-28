#include <iostream>

using namespace std;

//write a function a find the most appeared element in an array
int solanxuathien(int k, int n, int a[]){
	int count = 0, element[100];
	for (int i = 0; i < n; i++){
		if (a[i] == k) count++;
	}
	return count;
}
int mostAppearedElement(int a[], int n){
    int count, element[100];
    int k = 0;
    for (int i = 0; i < n-1; i++){
    	for (int j = i + 1; j < n; j++ ){
    		if ( a[i] < a[j]){
    			k = a[i];
    			a[i] = a[j];
    			a[j] = k;
			}
		}
	}
	int e=0;
	int max = solanxuathien(a[0], n, a);
	
	for (int i = 0; i < n; ++i){
		if (solanxuathien(a[i], n, a) >= max){
			max = solanxuathien(a[i], n, a);
			element[e] = a[i];
			e++;
		}
	}
	max = element[0];
	for (int i = 0; i <= e; ++i){
		if (element[i] > max){
			max = element[i];
		}
	}
	return max;
}

int main()
{
    int n, a[100];
    cin >> n;
    
    for (int i=0; i<n; i++)
        cin >> a[i];
   int k = 0;
    for (int i = 0; i < n-1; i++){
    	for (int j = i + 1; j < n; j++ ){
    		if ( a[i] < a[j]){
    			k = a[i];
    			a[i] = a[j];
    			a[j] = k;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
