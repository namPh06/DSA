#include <bits/stdc++.h>
using namespace std;
vector <int > List[305];
bool check[305];
int n,m,x;
void dfs(int u){
    check[u] = true;
    for (int v : List[u])
        if (!check[v]) dfs(v);
}
int main(){
    cin >> n >> m >> x;
    for (int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        List[u].push_back(v);
        List[v].push_back(u);
    }
    dfs(x);
    bool found = false;
    for (int i = 1; i <= n;i++){
        if (i == x || check[i] ) continue;
        cout << i << endl;
        found = true;
    }
    if (!found) cout << 0;
    return 0;
}