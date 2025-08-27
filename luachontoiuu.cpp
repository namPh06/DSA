#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector < pair<int,int >> v;
		for (int i = 0 ; i < n ; i++){
			int x,y;
			cin >> x >> y;
			v.push_back ({y,x});
		}
		sort (v.begin(), v.end());
		int cnt  = 1;
		int last = v[0].first;
		for (int i = 1 ; i< n ; i++){
			if (v[i].second >= last){
				cnt++;
				last  = v[i].first;
			}
		}
	    cout << cnt << endl;
	}
	return 0;
}