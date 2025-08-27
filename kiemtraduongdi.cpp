#include <bits/stdc++.h>
using namespace std;
int used[1001];
vector <int > v[1001];
int tmp[1001];
int n,m;
void nhap(){
	cin >> n >> m;
	for (int i = 1; i <= n ; i++){
		v[i].clear();
		used[i] = 0;
	}
	for (int i = 0; i < m ; i++){
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
	used[u] = 1;
	for (int x : v[u]){
		if (!used[x] )
		dfs(x);
	}
}
void dfsPath(int s , int t){
	for (int i = 1; i <= n; ++i) used[i] = 0;
	dfs(s);
	if (used[t]){
		cout <<"YES";
		return;
	}
	else {
		cout <<"NO";
		return;
	}
}
int main(){
	int tc;
	cin >> tc;
	while (tc--){
		nhap();
		int q;
		cin >> q;
		while (q--){
			int a,b;
			cin >> a >> b;
			dfsPath(a,b);
		}
		cout << endl;
	}
	return 0;
}