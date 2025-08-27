#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int h[n+1];
    for (int i = 1; i<=n ; i++){
        cin >> h[i];
    }
    long long dp[n + 1];
    dp[1] = 0;
    for (int i = 2 ; i <= n ;i++){
        dp[i] = 1e9;
        for (int j = max(1,i-k); j< i; j++){
            dp[i] = min(dp[i],dp[j] + abs (h[i] - h[j]));
        }
    }
    cout << dp[n];
}