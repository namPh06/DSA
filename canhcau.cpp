#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
int adj[200][200];
vector<pair<int, int>> edges_list;
bool f[200];

void dfs(int curr, int rmv_u, int rmv_v) {
    f[curr] = 1;
    for(int next = 1; next <= n; next++) {
        if(curr == rmv_u && next == rmv_v) continue;
        if(curr == rmv_v && next == rmv_u) continue;
        if(adj[curr][next] && !f[next]) {
            dfs(next, rmv_u, rmv_v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(adj[i][j]) {
                edges_list.push_back({i, j});
            }
        }
    }
    int origin_conn = 0;
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++) {
        if(!f[i]) {
            origin_conn++;
            dfs(i, -1, -1);
        }
    }
    vector<pair<int, int>> res;
    for(auto edge : edges_list) {
        int u = edge.first;
        int v = edge.second;
        int count = 0;
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; i++) {
            if(!f[i]) {
                count++;
                dfs(i, u, v);
            }
        }
        if(count > origin_conn) {
            res.push_back({u, v});
        }
    }
    cout << res.size() << '\n';
    for(auto edge : res) {
        cout << edge.first << ' ' << edge.second << '\n';
    }
}