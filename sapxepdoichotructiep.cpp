#include <bits/stdc++.h>
using namespace std;
void interchange_sort(int a[], int n){
	int s = 1;
	for (int i = 0 ; i < n - 1; i++){
		for (int j = i + 1 ; j < n; j++){
			if (a[i] > a[j])
			swap(a[i],a[j]);
		}
		cout << "Buoc " << s++ <<": ";
		for (int i = 0 ; i < n; i++){
		cout << a[i]<<" ";
	}
		cout << endl;
	}
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	interchange_sort(a,n);
	return 0;
}