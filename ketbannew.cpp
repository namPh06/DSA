#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAXN = 200005;
int parent[MAXN];
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}
void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv)
        parent[pu] = pv;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    set<int> roots;
    for (int i = 1; i <= n; i++) {
        roots.insert(find(i));
    }
    cout << roots.size() << "\n";
    return 0;
}
