#include <bits/stdc++.h>
using namespace std;
void hieu_min(int a[] , int k , int n){
	    sort (a ,a + n);
		long long sum1 =0 ,sum2 = 0 ;
		for (int i = 0 ; i< k ; i++){
			sum1 += a[i];
		}
		for (int i = k ; i < n ; i++){
			sum2 += a[i];
	}
	cout << sum2  - sum1 << endl;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n ,k;
		cin >>n  >> k;
		int a[n];
		for (int i = 0 ; i< n ; i++){
			cin >> a[i];
		}
		if ( k  <= (n- k))
		hieu_min(a,k,n);
		else hieu_min(a,n-k , n);
	}
	return 0;
}