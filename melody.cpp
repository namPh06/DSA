#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> sounds;
vector<vector<int>> adj;
vector<int> path;
vector<bool> used;
int n;

bool dfs(int node, int depth) {
    used[node] = true;
    path.push_back(node);
    
    if (depth == n - 1) {
        return true;
    }
    
    for (int next : adj[node]) {
        if (!used[next]) {
            // Check if adding this node would create three consecutive same values
            if (depth >= 1) {
                int prev = path[path.size() - 1];
                int prev_prev = path[path.size() - 2];
                if ((sounds[next].first == sounds[prev].first && sounds[prev].first == sounds[prev_prev].first) ||
                    (sounds[next].second == sounds[prev].second && sounds[prev].second == sounds[prev_prev].second)) {
                    continue;
                }
            }
            
            if (dfs(next, depth + 1)) {
                return true;
            }
        }
    }
    
    used[node] = false;
    path.pop_back();
    return false;
}

void solve() {
    cin >> n;
    
    sounds.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> sounds[i].first >> sounds[i].second;
    }
    
    // Build adjacency list
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            // Check if sounds differ only in volume or pitch
            if (sounds[i].first == sounds[j].first || sounds[i].second == sounds[j].second) {
                adj[i].push_back(j);
            }
        }
    }
    
    // Try to find a path starting from each node
    path.clear();
    used.resize(n);
    bool found = false;
    
    // Try starting from each node
    for (int start = 0; start < n; start++) {
        path.clear();
        fill(used.begin(), used.end(), false);
        if (dfs(start, 0)) {
            found = true;
            break;
        }
    }
    
    if (found) {
        cout << "YES\n";
        for (int x : path) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 