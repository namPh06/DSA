#include <bits/stdc++.h>
using namespace std;
void swapp(int a[], int n){
	int cnt = 0;
	for (int i = 0 ; i< n- 1;i++){
		int min_i = i;
		for (int j = i + 1 ; j < n ;j++){
			if  (a[j] < a[min_i])
			min_i = j;
		}
	    if (min_i != i){
		swap (a[i] , a[min_i]);
		cnt++;
	    }	    
	}
	cout << cnt << endl;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n ;
		int a[n];
		for (int i = 0 ; i< n ; i++){
			cin >> a[i];
		}
		swapp(a,n);
	}
	return 0;
}