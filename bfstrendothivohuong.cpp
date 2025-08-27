#include <bits/stdc++.h>
using namespace std;
vector <int > v[1001];
int used[1001];
int n ,  m , s;
void nhap(){
	cin >> n >> m >> s;
	for (int i = 1; i <= n ; i++){
		v[i].clear();
		used[i] = 0;
	}
	for (int i = 0 ; i < m ; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n ; i++){
		sort (v[i].begin() , v[i].end());
	}
}
void bfs(int u){
	queue <int > q;
	q.push (u);
	used[u] = 1;
	while (!q.empty()){
		int x = q.front();
		cout << x <<" ";
		q.pop();
		for (int i : v[x]){
			if (!used[i]){
				used[i] = 1;
				q.push(i);
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		nhap();
		bfs(s);
		cout << endl;
	}
}