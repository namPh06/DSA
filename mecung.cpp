#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool check(int v, vector<vector<int>>& adj, vector<bool>& visited, int parent) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            if (check(u, adj, visited, v))
                return true;
        } else if (u != parent) {
            return true;
        }
    }
    return false;
}

bool check1(int N, vector<vector<int>>& adj) {
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            if (check(i, adj, visited, -1))
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (check1(N, adj)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}