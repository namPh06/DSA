#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n ,k ;
		cin >> n >> k;
		int a[n];
		for (int i = 0 ; i< n ; i++){
			cin >> a[i];
		}
		sort (a ,a + n );
		bool check = false;
		for (int i = 0 ; i < n - 2 ; i++){
			int l = i+1 , r = n - 1;
			while (l < r){
				if (a[i] + a[l] + a[r] == k){
					check = true;
				     break;	
				}
				else if (a[i] + a[l] + a[r] < k)
			    l++;
			    else r--;
			}
		}
		if (!check) 
		cout <<"NO" << endl;
		else cout <<"YES" << endl;
	}
	return 0;
}