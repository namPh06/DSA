#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];
int disc[MAXN], low[MAXN], parent[MAXN];
int timer;
vector<pair<int, int>> cutVertices; 
void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;
    int components = 0; 
    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1)
                components = children;
            if (parent[u] != -1 && low[v] >= disc[u])
                components++;
        }
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (components > 0)
        cutVertices.push_back({u, components});
}
void resetGraph(int n) {
    timer = 0;
    cutVertices.clear();
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
        disc[i] = low[i] = 0;
        parent[i] = -1;
    }
}
int findMaxCutVertex(int n) {
    resetGraph(n);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    if (cutVertices.empty())
        return 0;
    int maxComponents = 0;
    int result = n + 1; 
    for (auto& p : cutVertices) {
        int vertex = p.first;
        int components = p.second;
        
        if (components > maxComponents) {
            maxComponents = components;
            result = vertex;
        } else if (components == maxComponents) {
            result = min(result, vertex);
        }
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        resetGraph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << findMaxCutVertex(n) << endl;
    }
    
    return 0;
}