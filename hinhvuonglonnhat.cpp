#include <bits/stdc++.h>
using namespace std;

int a[505][505], c[505][505], n, m;

int qhd() {
    int ans = 0;
    memset(c, 0, sizeof(c)); // Đặt lại mảng c

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                c[i][j] = min({c[i - 1][j], c[i][j - 1], c[i - 1][j - 1]}) + 1;
                ans = max(ans, c[i][j]); 
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(a, 0, sizeof(a)); 

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        cout << qhd() << endl;
    }
    return 0;
}
