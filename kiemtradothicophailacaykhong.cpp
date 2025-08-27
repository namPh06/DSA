#include <bits/stdc++.h>
using namespace std;
int used[1001] , n ;
vector <int > v[1001];
void nhap(){
	cin >> n;
	for (int i = 1; i<= n ; i++){
		used[i] = 0;
		v[i].clear();
	}
	for (int i = 0 ; i < n - 1 ; i++){
		int x  , y;
		cin >>x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}
void dfs(int u){
	used[u] = 1;
	for (int x : v[u]){
		if (!used[x])
		dfs(x);
	}
}
bool check(){
	dfs(1);
	for (int i = 1 ; i<= n ; i++){
		if (!used[i])
		return false;
	}
	return true;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		nhap();
		if (check())
		cout <<"YES\n";
		else cout <<"NO\n";
	}
	return 0;
}