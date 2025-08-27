#include <bits/stdc++.h>
using namespace std;
int n , m[100] , N[100] , p[100];
int res = 0;
void backtrack(int i){
	if ( i == n + 1){
		res++;
		return;
	}
	for (int j = 1; j <= n; j++){
		if (m[j] == 0 && N[j+i] == 0 && p[i - j + n] == 0){
			m[j] = N[j+i] = p[i-j+n]=1;
			backtrack(i+1);
			m[j] = N[j+i] = p[i-j+n]=0;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		res = 0;
		backtrack(1);
		cout << res <<"\n";
	}
	return 0;
}