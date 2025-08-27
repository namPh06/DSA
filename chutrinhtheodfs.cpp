#include <bits/stdc++.h>
using namespace std;
int used[1001] , n , m , tmp[1001];
int s, t;

vector <int > v[1001];
void nhap(){
	cin >> n >> m;
	for (int i =  1; i<= n ; i++){
		v[i].clear();
		used[i] = 0;
	}
	for(int i = 0 ; i < m ; i++){
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
			if (dfs(x)){
			return true;	
			}
		}
		else if (x != tmp[u]){
			s = x ; t = u;
			return true;
		}
	}
	return false;
}
int main(){
	int tc;
	cin >> tc;
	while (tc--){
		nhap();
		int ok = 0;
	    if (dfs(1)){
			ok = 1;
		}
		if (!ok)
		cout <<"NO\n";
		else {
			vector <int > path;
	    	path.push_back(s);
	    	while (s != t){
	    		path.push_back(t);
	    		t = tmp[t];
			}
			path.push_back(s);
			for (int i = path.size() - 1; i>= 0 ; i--){
				cout << path[i] <<" ";
			}
			cout << endl;

		}
	}
	return 0;
}