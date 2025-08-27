#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		for (int i = 0 ; i< n ; i++){
			cin >> a[i];
		}
		vector <int > v;
		for (int i = 0 ; i< n ; i++){
			if (a[i] != 0)
			v.push_back(a[i]);
		}
		sort (v.begin(),v.end());
	    long long x = 0 , y = 0;
		for (int i = 0 ; i< v.size() ; i++){
			if (i % 2 == 0)
			x = x* 10 + v[i];
			else y = y* 10 + v[i];
		}
		long long sum = x + y;
		cout << sum << endl;
	}
	return 0;
}