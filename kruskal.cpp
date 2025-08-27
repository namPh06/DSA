#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct E {
    int s, d, w;
};

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

bool c(E a, E b) {
    return a.w < b.w;
}

long long k(int v, vector<E>& e) {
    sort(e.begin(), e.end(), c);

    D d(v);
    long long m = 0;
    int u = 0;

    for (E x : e) {
        int px = d.f(x.s);
        int py = d.f(x.d);
        if (px != py) {
            d.u(px, py);
            m += x.w;
            u++;
            if (u == v - 1) break;
        }
    }

    if (u != v - 1) return -1;
    return m;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        vector<E> x(e);
        for (int i = 0; i < e; i++) {
            cin >> x[i].s >> x[i].d >> x[i].w;
        }
        long long r = k(v, x);
        cout << r << endl;
    }
    return 0;
}