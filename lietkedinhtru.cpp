#include <bits/stdc++.h>
using namespace std;
vector <int > v[1001];
int used[1001];
int n , m;
void nhap(){
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		v[i].clear();
		used[i] = 0;
	}
	for (int i = 0 ; i < m ; i++){
		int x , y;
		cin >> x >> y;
	    v[x].push_back(y);
	    v[y].push_back(x);
	}
	
}
void dfs(int u){
	used[u] = 1;
	for (int x : v[u]){
		if (!used[x])
		dfs(x);
	}
}
void dinhtru(){
	int cnt = 0; 
    for (int i =1 ; i <= n ; i++){
    	if (!used[i]){
    		cnt++;
    		dfs(i);
		}
	}
	for (int i =1 ; i <= n ; i++){
        memset (used, 0 , sizeof(used));
		used[i] = 1;
		int dem = 0;
		for (int j =1 ; j <= n ; j++){
			if (!used[j]){
				dem++;
				dfs(j);
			}
		}
		if (dem > cnt){
			cout << i << " ";
		}
	}
	cout << endl;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		nhap();
		dinhtru();
	}
	return 0;
}