#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> value_positions;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        value_positions[a[i]].push_back(i);
    }
    
    // Process values in descending order
    set<int> active_indices;
    int clones = 0;
    for (auto it = value_positions.rbegin(); it != value_positions.rend(); ++it) {
        auto &positions = it->second;
        bool need_new_clone = false;
        for (int pos : positions) {
            auto it_active = active_indices.upper_bound(pos);
            if (it_active != active_indices.end() && a[*it_active] > it->first) {
                // There's a higher value to the right in active_indices, so can extend
            } else if (it_active != active_indices.begin() && a[*(prev(it_active))] > it->first) {
                // There's a higher value to the left in active_indices, so can extend
            } else {
                need_new_clone = true;
            }
        }
        if (need_new_clone) {
            clones++;
        }
        for (int pos : positions) {
            active_indices.insert(pos);
        }
    }
    cout << clones << '\n';
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