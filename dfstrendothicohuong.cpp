#include <bits/stdc++.h>
using namespace std;
int n , m , s;
vector <int > v[1001];
int used[1001];
void nhap(){
    cin >> n >> m >> s;
    for (int i = 1 ; i <= n ; i++){
        v[i].clear();
        used[i] = 0;
    }
    for (int i = 0 ; i< m ; i++){
        int x , y;
        cin >> x >> y;
        v[x].push_back(y);
    }
}
void dfs (int u){
    cout <<  u << " ";
    used[u] = 1;
    for (int  x : v[u]){
        if (!used[x])
        dfs(x);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        nhap();
        dfs(s);
        cout << endl;
    }
    return 0;
}