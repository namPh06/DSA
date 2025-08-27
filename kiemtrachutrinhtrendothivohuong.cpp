#include <bits/stdc++.h>
using namespace std;
int used[1001] , tmp[1001] , n , m;
vector <int > v[1001];
void nhap(){
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		used[i] = 0;
		v[i].clear();
	}
	for (int i = 0 ; i < m ; i++){
		int x , y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}
bool dfs(int u){
	used[u] = 1;
	for (int x : v[u]){
		if (!used[x]){
			tmp[x] = u;
			if (dfs(x)) return true;
		}
		else if ( x != tmp[u]) 
		return true;
	}
	return false;;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		nhap();
		int ok = 0;
		for (int i = 1; i<= n ; i++){
			if (!used[i]){
				if (dfs(i)){
					cout << "YES\n";
					ok = 1;
					break;
				}
			}
		}
		if (!ok)
		cout <<"NO\n";
	}
}