#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    
    // Constructor
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    
    // Comparator for sorting edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (DSU) class
class DSU {
private:
    vector<int> parent, rank;
    
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<Edge> edges;
    
    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back(Edge(u, v, w));
    }
    
    // Sort edges by weight
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    vector<Edge> mst;
    int totalWeight = 0;
    
    // Kruskal's algorithm
    for (const Edge& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }
    
    // Check if MST exists (connected graph)
    if (mst.size() != n - 1) {
        printf("0\n");
        return 0;
    }
    
    // Output results
    printf("%d\n", totalWeight);
    for (const Edge& edge : mst) {
        printf("%d %d %d\n", edge.u, edge.v, edge.weight);
    }
    
    return 0;
} 