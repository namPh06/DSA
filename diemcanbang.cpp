#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >>t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		int sum =  0;
		for (int i = 0 ; i< n ; i++){
			cin >> a[i];
			sum += a[i];
		}
		int l = 0 , r = sum;
		bool check = false;
		for (int i = 0 ; i < n ; i++){
			r -= a[i];
			if (l == r){
				cout << i+1 << endl;
				check = true;
				break;
			}
			l += a[i];
		}
		if (!check)
		cout <<"-1" << endl;
	}
	return 0;
}