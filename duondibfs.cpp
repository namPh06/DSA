#include <bits/stdc++.h>
using namespace std;

vector<int> findPathBFS(int V, vector<vector<int>>& adj, int u, int v) {
    vector<bool> visited(V + 1, false);
    vector<int> parent(V + 1, -1);
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == v) {
            vector<int> path;
            int node = v;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            return path;
        }
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    return vector<int>(); 
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E, u, v;
        cin >> V >> E >> u >> v;
        vector<vector<int>> adj(V + 1);
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        vector<int> path = findPathBFS(V, adj, u, v);
        
        if (path.empty()) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
