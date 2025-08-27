#include <iostream>
#include <vector>
using namespace std;

struct D {
    vector<int> p, r;
    D(int n) {
        p.resize(n + 1);
        r.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }

    int f(int u) {
        if (p[u] != u) {
            p[u] = f(p[u]);
        }
        return p[u];
    }

    void u(int x, int y) {
        int px = f(x), py = f(y);
        if (px == py) return;
        if (r[px] < r[py]) {
            p[px] = py;
        } else if (r[px] > r[py]) {
            p[py] = px;
        } else {
            p[py] = px;
            r[px]++;
        }
    }
};

int main() {
    int q;
    cin >> q;
    D d(100000);
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1) {
            d.u(x, y); 
        } else {
            int px = d.f(x);
            int py = d.f(y);
            cout << (px == py ? "1" : "0") << endl;
        }
    }
    return 0;
}