#include <bits/stdc++.h>
using namespace std;
vector <int > v[1001];
int used[1001];
int n,m ;
int a[1001][1001];
vector <pair <int,int >> vp;
void nhap(){
	cin >> n;
	for (int i = 1 ;i <= n ; i++){
        for (int j = 1 ;j <= n ;j++){
            cin >>a [i][j];
            if (a[i][j] == 1 && i < j){
                v[i].push_back(j);
                v[j].push_back(i);
                vp.push_back({i,j});
            }
        }
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
            ans++;
		}
	}
    cout << ans;
}
int main(){
		nhap();
		canhcau();
		cout << endl;
	return 0;
}