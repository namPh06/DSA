#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i  = 0;i<n;i++){
		cin >> a[i];
	}
	int x;
	cin >> x;
	vector <int > v;
	for (int z : a){
	if 	(z != x)
	v.push_back(z);
	}
	for (int x : v){
		cout << x <<" ";
	}
	return 0;
}