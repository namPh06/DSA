#include <bits/stdc++.h>
using namespace std;
int const mod = 1000000007;
long long fibo(long long n){
	vector <long long > v(1000000000);
	v[0] = 0;
	v[1] = 1;
	for (int i = 2; i<= 1000000000; i++){
		v[i] = (v[i-1] + v[i-2]) % mod;
	}
	return v[n];
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		cout << fibo(n) << endl;
	}
	return 0;
}