#include <bits/stdc++.h>
using namespace std;
int const mod = 1000000007;
long long tn(long long n){
	long long res = 0;
	while ( n != 0){
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}
long long superpow(long long a,long long b, long long m){
	if (b == 0)
	return 1;
	long long r = superpow(a,b/2,m);
	r = (r*r) % m;
	if (b % 2 == 1)
	r = (r*a) % m;
	return r;
	
}
int main(){
	int t;
	cin >> t;
	while (t--){
		long long n;
		cin >> n;
		long long b = tn(n);
		cout << superpow(n,b,mod) << endl;
	}
	return 0;
}