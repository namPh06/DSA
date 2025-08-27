#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
    int n,k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n ; i++){
        cin >> a[i];
    }
    int res = n + 1;
    for (int i = 0; i < n ; i++){
        long long gcd = 0;
        for (int j = i ; j< n ; j++){
            gcd = __gcd(a[j],gcd);
            if (gcd == k){
                res = min(res,j-i+1);
                break;
            }
        }
    }
    if (res == n + 1)
    cout << "-1" << endl;
    else cout << res << endl;
}
    return 0;
}