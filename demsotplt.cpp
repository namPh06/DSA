#include <bits/stdc++.h>
using namespace std;
vector <int > v[1001];
int tmp[1001], used[1001];
int n,m;
void nhap(){
	cin >> n >> m;
	for (int i = 1; i <= n ; i++){
		v[i].clear();
		used[i] = 0;
	}
	for(int i = 0 ; i < m ; i++){
		int x , y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1 ; i <= n; i++){
		sort (v[i].begin() , v[i].end());
	}
}
void dfs(int u){
	used[u] = 1;
	for (int x : v[u]){
		if (!used[x]){
			dfs(x);
		}
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int cnt = 0;
		nhap();
		for (int i = 1 ; i<= n ; i++){
			if (!used[i]){
				cnt++;
				dfs(i);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
