#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n,k;
		cin >> n >> k ; 
		int a[n];
		for (int i = 0 ; i <  n ; i ++) {
			cin >> a[i];
		}
		map <int,int > mp;
		long long cnt = 0 ;
		for (int i = 0 ; i < n ; i++){
			int res = k - a[i];
			if (mp.find (res) != mp.end()){
				cnt += mp[res];
			}
			mp[a[i]]++;
		}
     cout << cnt << endl;
	 }
	 return 0;
}