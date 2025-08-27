#include <bits/stdc++.h> 
using namespace std;
bool cmp (pair <int,int > a, pair <int,int > b){
	return a.second > b.second;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n ;
		cin >> n ;
		int a[n];
		map <int,int > mp;
		int ans = 0;
		for (int i = 0 ; i < n ; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
	    vector < pair < int,int >> v;
	    for (int i = 0 ; i < n ; i++){
	    	if (mp[a[i]] > n / 2)
	    	v.push_back ({a[i] , mp[a[i]]});
		}
		if (v.size() == 0) 
		cout <<"NO" << endl;
		else {
		sort (v.begin() , v.end(),cmp);
		
		for (auto it :v){
			cout << it.first << endl;
			break;
		}
	}
	}
	return 0;
}