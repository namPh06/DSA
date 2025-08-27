#include <bits/stdc++.h>
using namespace std;
long long f[93];
string solve (long long n , long long k){
    if ( n == 1)
    return "0";
    if (n == 2)
    return "1";
    if (k  <= f[n-2])
    return solve (n-2, k);
    else return solve ( n - 1, k - f[n-2]);
}
int main(){
    int t;
    cin >> t;
    f[1] = f[2] = 1;
    for (int i =  3; i <= 92 ; i++){
        f[i] = f[i-2] + f[i-1];
    }
    while (t--){
        long long n , k;
        cin >> n >> k;
        cout << solve(n, k) <<"\n";
    }
    return 0;
}