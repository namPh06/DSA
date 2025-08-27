#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
vector<int> adj[MAXN];
vector<pair<int, int>> edges;
int n, m, t, u;
vector<int> degree(MAXN, 0);
vector<bool> visited(MAXN, false);
vector<int> path;
bool isConnected() {
    fill(visited.begin(), visited.end(), false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] > 0 && !visited[i]) {
            return false;
        }
    }
    
    return true;
}

bool isEulerian() {
    if (!isConnected()) {
        return false;
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            return false;
        }
    }
    
    return true;
}
bool isSemiEulerian() {
    if (!isConnected()) {
        return false;
    }
    int oddCount = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            oddCount++;
        }
    }
    return oddCount == 2;
}
void findEulerCircuit(int v) {
    while (!adj[v].empty()) {
        int u = adj[v].back();
        adj[v].pop_back();
        for (int i = 0; i < adj[u].size(); i++) {
            if (adj[u][i] == v) {
                adj[u].erase(adj[u].begin() + i);
                break;
            }
        } 
        findEulerCircuit(u);
    }
    
    path.push_back(v);
}

int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    
    cin >> t;
    
    if (t == 1) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            degree[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        if (isEulerian()) {
            cout << 1 << endl;
        } else if (isSemiEulerian()) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
    } else if (t == 2) {
        cin >> n >> m >> u;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            degree[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        path.clear();
        findEulerCircuit(u);
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i > 0) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}