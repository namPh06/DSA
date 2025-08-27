#include <bits/stdc++.h>
using namespace std;
int const mod = 1000000007;
long long superpow(long long a,long long b, long long m){
	if (b == 0 )
	return 1;
	long long r = superpow(a,b/2,m);
	r = (r*r) % m;
	if (b % 2 == 1)
	r = (r*a) % m;
	return r;
}

int main(){
	long long a ,b ;
	while (cin >> a >> b){
		if (a == 0 && b == 0 )
		break;
		cout << superpow(a,b,mod) << endl;	
	}
	return 0;
}