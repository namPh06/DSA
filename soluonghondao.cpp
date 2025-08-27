#include <bits/stdc++.h>
using namespace std;
vector <int > v[1001];
int used[1001];
int n , m;
int a[1001][1001];
void nhap(){
	cin >> n >> m;
	for (int i = 1 ; i<= n ; i++){
		used[i] = 0;
		v[i].clear();
	}
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < m ; j++){
			cin >> a[i][j];
			if (a[i][j] == 1){
				v[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n ; i++){
		sort(v[i].begin() , v[i].end());
	}
}
void dfs(int u){
	used[u] = 1;
	for (int x : v[u]){
		if (!used[u]){
			dfs(x);
		}
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		nhap();
		int cnt = 0 ;
		for(int i =1 ; i <= n ; i++){
			if (!used[i]){
				cnt++;
				dfs(i);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}