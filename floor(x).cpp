#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n,x;
		cin >> n >> x;
		long long a[n];
		for (int i = 0 ; i < n;i++){
			cin >> a[i];
		}
		vector < long long > v;
		for (long long r : a){
			if (r <= x) 
			v.push_back(r);
		}
		if (v.size() == 0)
		cout <<"-1" << endl;
		else cout << v.size() << endl;
	}
	return 0;
}