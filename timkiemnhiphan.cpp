#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n,k ;
		cin >> n >> k;
		int a[n];
		for (int i = 0 ; i < n;i++){
			cin >> a[i];
		}
		int check = 0;
		for (int i = 0 ; i < n;i++){
			if (a[i] == k){
				cout << i + 1;
				check = 1;
				break;
			}
		}
		if (check == 0)
		cout <<"No";
		cout << endl;
	}
	return 0;
}