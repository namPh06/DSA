#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt(vector<int> v, int x) {
    return v.end() - upper_bound(v.begin(), v.end(), x);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> X(n), Y(m);
        for (int i = 0; i < n; i++) cin >> X[i];
        for (int i = 0; i < m; i++) cin >> Y[i];
        sort(Y.begin(), Y.end());
         int count[5] = {0}; 
    for (int y : Y) {
        if (y < 5) count[y]++;
    }
    int total = 0;
    for (int x : X) {
        if (x == 0) continue;
        if (x == 1) {
            total += count[0]; 
            continue;
        }
        int ans = cnt(Y, x);
        ans += count[1];
        if (x == 2) ans -= (count[3] + count[4]);
        if (x == 3) ans += count[2];
        total += ans;
    }
        cout <<total << endl;
    }
    return 0;
}
