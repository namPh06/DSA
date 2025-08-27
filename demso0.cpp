#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		vector <int > v;
		for (int i = 0 ; i < n ; i++){
			cin >> a[i];
			if (a[i] == 0)
			v.push_back(a[i]);
		}
		cout << v.size() << endl;
	}
	return 0;
}