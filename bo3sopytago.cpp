#include <bits/stdc++.h>
using namespace std;
bool check(long long a[] , int n){
	for (int i = 0 ;i < n ; i++){
		a[i] = a[i] * a[i];
	}
	sort (a,a+n);
	for (int i = n - 1; i >= 2; i --){
		int l = 0 , r = i - 1;
		while (l < r){
			if (a[l] + a[r] == a[i])
			return true;
			else if (a[l] + a[r] > a[i] )
			r--;
			else l++;
		}
	}
	return false;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
	long long a[n];
		for (int i = 0 ; i< n ; i++){
			cin >> a[i];
		}
		if (check(a,n))
		cout <<"YES\n";
		else cout <<"NO\n";
	}
	return 0;
}