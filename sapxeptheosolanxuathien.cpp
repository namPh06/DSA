#include <bits/stdc++.h>
using namespace std;
bool cmp (pair < int,int > a , pair <int,int > b){
    if (a.second != b.second)
    return a.second > b.second;
    return a.first < b.first;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		map <int ,int > mp;
		for (int i = 0 ; i < n;i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		vector <pair <int,int >> v;
		for (int i = 0 ; i < n;i++){
			v.push_back({a[i],mp[a[i]]});
		}
		sort(v.begin(),v.end(),cmp);
		for (auto it : v){
			cout << it.first <<" ";
		}
		cout << endl;
	}
	return 0;
}