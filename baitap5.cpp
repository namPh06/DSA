#include <bits/stdc++.h>
using namespace std;
long long f[46];
void solve(){
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i<= 45; i++){
        f[i] = f[i-1] +f[i-2];
    }
}
long long dem (int n ,long long k){
    if (n == 0)
    return 1;
    if (n== 1)
    return 0;
    long long cnt = 0;
    if ( k <= f[n-1])
    cnt += dem(n-1, k);
    else cnt += dem(n-1,f[n-1]) + dem (n-2,k-f[n-1]);
    return cnt;
}
int main(){
    int t;
    cin >> t;
    solve();
    while (t--){
       int n;
       long long k;
       cin >> n >> k;
       cout << dem (n,k) << endl;
    }
    return 0;
}