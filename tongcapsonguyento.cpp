#include <bits/stdc++.h>
using namespace std;
int prime[1000000];
int n = 1000000;
void seive (){
	for (int i=0;i<=n;i++){
		prime [i]=1;	
	}
	prime[0] = prime [1] = 0;
	for (int i=2;i<sqrt(n);i++){
		if (prime[i]){
			for (int j=i*i;j<=n;j+=i){
				prime [j]=0;
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	seive();
	while (t--){
		int n;
		cin >> n;
		int ok = 0;
		for (int i = 2 ; i <= n / 2; i++){
			if (prime[i] && prime[n - i])
			{
			cout << i <<" "<< n - i << endl;
			ok = 1;
			break;
		    }
		}
		if (ok == 0)
		cout << "-1" << endl;;
	}
	return 0;
}