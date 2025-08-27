#include <bits/stdc++.h>
using namespace std;
int used[1001];
vector <int > v[1001];
int n,m,s;
void nhap(){
	cin >> n >> m >> s;
	for (int i = 1; i <= n ; i++){
		v[i].clear();
		used[i] = 0;
	}
	for ( int i = 0; i < m ; i++){
		int x , y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n ; i++){
		sort (v[i].begin() , v[i].end());
	}
}
void dfs(int u){
	cout << u <<" ";
	used[u] = 1;
	for (int a : v[u]){
		if (!used[a])
		dfs(a);
	}
}
int main(){
	int t;
	cin >> t;
    while (t--){
    	nhap();
    	dfs(s);
    	cout << endl;
	}
	return 0;
}