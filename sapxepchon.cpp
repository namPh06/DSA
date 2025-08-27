#include<bits/stdc++.h>
using namespace std;
void selection_sort(int a[] , int n){
	int s = 1;
	for (int i = 0 ; i < n- 1; i++){
		int min_i = i ;
		for (int j = i + 1 ; j < n ;j++){
			if (a[j] < a[min_i])
			min_i = j;
		}
		swap(a[i] , a[min_i]);
		cout <<"Buoc " <<s++<<": ";
		for (int i = 0 ; i < n ; i++){
			cout << a[i] <<" ";
		}
		cout << endl;
	}
}
int main(){
	int n;
	cin >> n;
	int a[101];
	for (int i = 0 ; i < n; i++){
		cin >> a[i];
	}
	selection_sort(a,n);
	return 0 ;
}