#include <bits/stdc++.h>
using namespace std;
int n, m , used[1001]; 
vector <int > v[1001] , tmp[1001];
stack <int > st;
void nhap(){
	cin >> n >> m;
	for (int i = 1 ; i<= n ; i++){
		v[i].clear();
		tmp[i].clear();
		used[i] = 0;
	}
	for (int i = 0; i < m ; i++){
		int x, y;
		cin >>x  >> y;
		v[x].push_back(y);
		tmp[y].push_back(x);
	}
}
void dfs1(int u){
	used[u] = 1;
	for (int x : v[u]){
		if (!used[x])
		dfs1(x);
	}
	st.push(u);
}
void dfs2(int u){
	used[u] = 1;
    for (int x : tmp[u]){
    	if (!used[x])
            dfs2(x);
 	}  
}
void check(){
	for (int i = 1; i<= n ; i++){
		if (!used[i]){
			dfs1(i);
		}
	}
	memset (used,0 ,sizeof (used));
	int cnt = 0;
	while (!st.empty()){
		int u = st.top();
		st.pop();
		if (!used[u]){
			dfs2(u);
			cnt++;
		}
	}
	if (cnt == 1)
	cout <<"YES\n";
	else cout <<"NO\n";
}
int main(){
	int t;
	cin >> t;
	while (t--){
		nhap();
		check();
	}
}