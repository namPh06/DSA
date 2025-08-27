#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> cnt(m);
    int total = 0;

    for (int i = 0; i + 1 < n; ++i) {
        int cur = a[i];
        int nxt = a[i + 1];
        if (cur <= nxt) continue;
        int need = (m - nxt + cur) % m;
        cnt[need]++;
        total++;
    }
    int res = total;
    for (int k = 1; k < m; ++k) {
        res = min(res, total - cnt[k]);
    }

    cout << res << '\n';
    return 0;
}
