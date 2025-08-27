#include <bits/stdc++.h>
using namespace std;
int n,m, tplt[1001] , used[1001];
vector <int > v[100001];
int cnt;
void nhap(){
	 ios::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m ;i++){
		int x , y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n ;i++){
		sort (v[i].begin() , v[i].end());
	}
	cnt = 0;
}
void dfs(int u){
	used[u] = 1;
	tplt[u] = cnt;
	for (int x : v[u]){
		if (!used[x])
		dfs(x);
	}
}
void solve(){
	nhap();
	for (int i = 1; i <= n ; i++){
		if (!used[i] ){
			cnt++;
			dfs(i);
		}
	}
	int ans = 0;
	int sz[1001];
	memset (sz , 0 , sizeof (sz));
	for (int i =1 ; i <= n ;i++){
		if (tplt[i] == 1)
		ans	++;
		else sz[tplt[i]]++;
	}
	int mx = -1;
	for (int i =1 ; i <= n ;i++){
		mx = max(mx, sz[i]);
	}
	cout << ans + mx;
	cout << "\n";
}
int main(){
	solve();
	return 0;
}