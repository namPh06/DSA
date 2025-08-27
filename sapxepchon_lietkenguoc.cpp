#include<bits/stdc++.h>
using namespace std;
void selection_sort(int a[] , int n){ 
    vector <vector <int > > v;
	for (int i = 0 ; i < n- 1; i++){
		int min_i = i ;
		for (int j = i + 1 ; j < n ;j++){
			if (a[j] < a[min_i])
			min_i = j;
		}
		swap(a[i] , a[min_i]);
	    vector < int > x;
	    for (int i = 0 ; i < n;i++){
	    	x.push_back (a[i]);
		}
		v.push_back(x);
	}
	for (int i = v.size() - 1 ; i >= 0 ; i--){
		cout << "Buoc "<< i+ 1 <<": ";
		for (int j = 0; j < n ;j ++){
			cout << v[i][j] <<" ";
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