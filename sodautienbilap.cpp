#include <bits/stdc++.h>
using namespace std;
bool cmp (pair <int,int > a , pair <int,int > b){
      return a.second < b.second;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		map <int,int > mp;
		set <int > se;
		for (int i = 0 ; i < n ; i++){
			cin >>  a[i];
			mp[a[i]]++;
			se.insert(a[i]);
		}
		if (se.size() < n){
			vector <pair <int,int > >v;
		for (int i = 0 ; i < n ; i ++){
			if (mp[a[i]] >= 2)
			v.push_back ({a[i],i});
		}
		sort (v.begin(), v.end(),cmp);
		for (auto it : v){
			cout << it.first << endl;
			break;
		}
		}
		else cout <<"NO" << endl;
	}
	return 0;
}
