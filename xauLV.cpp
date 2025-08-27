#include <bits/stdc++.h>
using namespace std;
long long f[93];
string solve (long long n , long long k ){
    if (n == 1)
    return "L";
    if (n==2)
    return "V";
    if (k == f[n-1] + 1 ){
        if (n % 2 == 1)
        return "L";
        else return "V";
    }
    if ( k <= f[n-1])
    return solve (n- 1, k);
    return solve (n-2 , k - f[n-1] - 1);
}
int main(){
     cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    f[1]= 1;
    f[2] =1 ;
    for (int i = 3; i <= 93 ; i++){
        f[i] = f[i-1 ] + f[i-2] + 1;
    }
    while (t--){
        long long n , k;
        cin >> n >> k;
        cout << solve (n,k) <<"\n";
    }
    return 0;
}