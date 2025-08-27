#include <bits/stdc++.h>
using namespace std;
vector <int > v[1001];
int used[1001];
int n,m ;
vector <pair <int,int >> vp;
void nhap(){
	cin >> n >> m;
	vp.clear();
	for (int i =1 ; i <= n ; i++){
		v[i].clear();
		used[i] = 0;
	}
	for (int i = 0 ;i < m ; i++){
		int x , y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		vp.push_back({x,y});
	}
}
void dfs(int u){
	used[u] = 1;
    for (int x : v[u]){
    	if (!used[x])
    	dfs(x);
	}
}
void dfs2(int u , int s, int t){
	used[u] = 1;
	for (int x : v[u]){
		if ((u == s && x == t) || (u == t && x == s))
		continue;
		if (!used[x])
		dfs2(x,s, t);
	}
}
void canhcau(){
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= n ; i++){
		if (!used[i]){
			cnt++;
			dfs(i);
		}
	}
	for (auto it : vp){
		int x = it.first , y = it.second;
		memset (used, 0 , sizeof (used));
		int dem = 0;
		for (int j = 1; j <= n ; j++){
			if (!used[j]){
				dem++;
				dfs2(j,x,y);
			}
		}
		if (dem > cnt){
			cout << x <<" "<< y <<" ";
		}
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		nhap();
		canhcau();
		cout << endl;
	}
	return 0;
}