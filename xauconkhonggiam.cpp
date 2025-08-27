#include <bits/stdc++.h>
using namespace std;
int dp[5001];
void solve(){
    int n;
    string s;
    cin >> n >> s;
    s = "@" + s;
    int res = 1;
    for (int i =1 ;i <= s.size() ; i++){
        dp[i] = 1;
        for (int j = 1 ; j < i ; j++){
            if (s[i] >= s[j])
            dp[i] = max(dp[i] , dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    cout << endl;
}