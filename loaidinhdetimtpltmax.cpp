#include <bits/stdc++.h>
using namespace std;
vector<int> v1[1005];
bool visited[1005];
int N, M;
void dfs(int u, int x) {
    visited[u] = true;
    for (int v : v1[u]) {
        if (!visited[v] && v != x)
            dfs(v, x);
    }
}

int demtplt(int x) {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i != x && !visited[i]) {
            dfs(i, x);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        for (int i = 0; i <= N; i++) v1[i].clear();
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            v1[u].push_back(v);
            v1[v].push_back(u);    
        }
        int res= 1;
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            int tplt = demtplt(i);
            if (tplt > res) {
                res = tplt;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
