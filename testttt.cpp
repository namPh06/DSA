#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int INF = 10000 + 1;

int n, s, t;
int c[MAXN][MAXN];
int d[MAXN], trace[MAXN];
bool visited[MAXN];

void dijkstra(int s) {
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
        visited[i] = false;
        trace[i] = -1;
    }
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int v = 1; v <= n; ++v) {
            if (c[u][v] < INF && d[v] > d[u] + c[u][v]) {
                d[v] = d[u] + c[u][v];
                trace[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    // freopen("DN.INP", "r", stdin);
    // freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];

    dijkstra(s);

    if (d[t] >= INF) {
        cout << 0;
    } else {
        cout << d[t] << endl;
        vector<int> path;
        int v = t;
        while (v != -1) {
            path.push_back(v);
            v = trace[v];
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i + 1 < path.size()) cout << " ";
        }
    }
    return 0;
}