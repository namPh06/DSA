#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		set < int > se;
		for (int i = 0 ; i < n;i++){
			cin >> a[i];
			se.insert(a[i]);
		}
		sort (a,a+n);
		int res = a[n - 1] - a[0] + 1;
		int ans = res - se.size();
		cout << ans << endl;
	}
	return 0;
}