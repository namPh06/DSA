#include <bits/stdc++.h>
using namespace std;
int qhd(string S) {
    int n = S.length();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (S[j] <= S[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    string s;
    cin >> s;
    cout << qhd(s);
    return 0;
}