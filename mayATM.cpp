#include <bits/stdc++.h>
using namespace std;

int n;
long long S, t[35];
int res = INT_MAX;

void Try(int i, long long sum, int cnt) {
    if (sum > S || cnt >= res) return;
    if (sum == S) {
        res = cnt;
        return;
    }
    if (i == n) return;
    Try(i + 1, sum, cnt);
    Try(i + 1, sum + t[i], cnt + 1);
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> S;
        for (int i = 0; i < n; i++) cin >> t[i];
        sort(t, t + n, greater<>()); 
        res = INT_MAX;              
        Try(0, 0, 0);
        if (res == INT_MAX) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
