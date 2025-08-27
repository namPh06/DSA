#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<pair<int, int>> obs(n);
    for (int i = 0; i < n; i++) {
        cin >> obs[i].first >> obs[i].second;
    }

    unordered_set<int> cur_heights;
    cur_heights.insert(0);
    vector<vector<int>> from(n + 1); // để backtrack đáp án

    for (int i = 0; i < n; ++i) {
        unordered_set<int> next_heights;
        vector<int> prev(n + 1, -1);
        for (int h : cur_heights) {
            for (int di = 0; di <= 1; ++di) {
                if (d[i] != -1 && d[i] != di) continue;
                int nh = h + di;
                if (nh >= obs[i].first && nh <= obs[i].second) {
                    next_heights.insert(nh);
                }
            }
        }

        if (next_heights.empty()) {
            cout << -1 << '\n';
            return;
        }

        cur_heights = next_heights;
        from[i + 1].assign(n + 1, -1);
        for (int h : cur_heights) {
            for (int di = 0; di <= 1; ++di) {
                if (d[i] != -1 && d[i] != di) continue;
                int ph = h - di;
                if (ph >= 0 && cur_heights.count(h) &&
                    ph >= obs[i - 1 >= 0 ? i - 1 : 0].first &&
                    ph <= obs[i - 1 >= 0 ? i - 1 : 0].second) {
                    from[i + 1][h] = di;
                }
            }
        }
    }

    // tìm trạng thái cuối cùng
    int last_h = -1;
    for (int h : cur_heights) {
        last_h = h;
        break;
    }

    vector<int> res(n);
    for (int i = n; i >= 1; --i) {
        int di = from[i][last_h];
        if (di == -1) di = 0;
        res[i - 1] = di;
        last_h -= di;
    }

    for (int x : res) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
