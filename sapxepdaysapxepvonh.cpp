#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n , x;
		cin >> n >> x;
		int a[n];
		for (int i = 0 ; i< n;i++){
			cin >> a[i];
		}
		int check = 0;
		for (int i = 0 ; i < n;i++){
			if (a[i] == x){
				check = 1;
				cout << i + 1;
				break;
			}
		}
		cout << endl;
	}
	return 0;
}