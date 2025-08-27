#include <bits/stdc++.h>
using namespace std;
const int max_len = 101; 
int dp[max_len][max_len];

int qhd( string s, int n) {
    memset(dp, 0, sizeof(dp)); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s[j - 1] && i != j)
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else        
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << qhd(s,n) << endl;
    }
    return 0;
}