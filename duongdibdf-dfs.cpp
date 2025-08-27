#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int MAXN = 1005;
vector<int> adj[MAXN]; 
bool visited[MAXN];
int parent[MAXN];
bool dfs(int start, int target) {
    fill(visited, visited + MAXN, false);
    fill(parent, parent + MAXN, -1);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        
        if (u == target) return true;
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                s.push(v);
            }
        }
    }
    
    return false;
}
bool bfs(int start) {
    fill(visited, visited + MAXN, false);
    fill(parent, parent + MAXN, -1);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == 1) return true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    return false;
}
void printPath(int start, int end) {
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    for (int i = 2; i <= n; i++) {
        if (dfs(1, i)) {
            printPath(1, i);
        } else {
            cout << "-1" << endl;
        }
        if (bfs(i)) {
            printPath(i, 1);
        } else {
            cout << "-1" << endl;
        }
    }
    
    return 0;
}