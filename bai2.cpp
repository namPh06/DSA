#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

int n, u;
int adj[200][200];
int deg[200];
bool f[200];

void dfs(int curr) {
    f[curr] = 1;
    for(int next = 1; next <= n; next++) {
        if(adj[curr][next] && !f[next]) {
            dfs(next);
        }
    }
}

int euler_check() {
    memset(f, 0, sizeof(f));
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(!f[i]) return 0;
    }
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i] % 2 != 0) {
            count++;
        }
    }
    if(count == 0) return 1;
    else if(count <= 2) return 2;
    else return 0;
}

vector<int> euler_path() {
    vector<int> path;
    stack<int> s;
    s.push(u);
    while(!s.empty()) {
        int top = s.top();
        bool ok = 1;
        for(int i = 1; i <= n; i++) {
            if(adj[top][i]) {
                ok = 0;
                adj[top][i] = adj[i][top] = 0;
                s.push(i);
                break;
            }
        }
        if(ok) {
            path.push_back(top);
            s.pop();
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    int t;
    cin >> t;
    if(t == 1) {
        cin >> n;
    } else {
        cin >> n >> u;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if(adj[i][j]) deg[i]++;
        }
    }
    if(t == 1) {
        cout << euler_check();
    } else {
        auto res = euler_path();
        for(auto v : res) {
            cout << v << ' ';
        }
    }
}