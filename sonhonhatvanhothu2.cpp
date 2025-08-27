#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		set <int > se;
		for (int i = 0 ; i< n;i++){
			cin >> a[i];
			se.insert(a[i]);
		}
		sort(a,a+n);
		if (se.size() == 1)
		cout << "-1\n";
		else cout << a[0] <<" " << a[1] << endl;
	}
	return 0;
}