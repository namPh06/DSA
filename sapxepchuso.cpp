#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		for (int i = 0 ; i < n;i++){
			cin >> a[i];
		}
		set < int > se;
		for (int i = 0  ; i < n;i++){
			while (a[i] != 0){
				se.insert(a[i] % 10);
				a[i] /= 10;
			}
		}
		for (int x  : se){
			cout << x <<" ";
		}
		cout << endl;
	}
	return 0;
}