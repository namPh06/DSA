#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
vector < int > v[maxn];
int a[maxn];
int used[maxn] , n , m;
void nhap(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n ; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m ; i++){
        int x,y;
        cin >>x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1;i <= n ; i++){
        sort (v[i].begin(), v[i].end());
    }
}
long long dfs(int u){
    used[u] = 1;
    long long ans = a[u];
    for (int x : v[u]){
        if (!used[x]){
            ans = min(ans, dfs(x));
        }
    }
    return ans;
}
int main(){
    nhap();
    long long res = 0;
    for (int i = 1; i <= n; i++){
        if (!used[i]){
            res += dfs(i);
        }
    }
    cout <<res ;
    return 0;
}