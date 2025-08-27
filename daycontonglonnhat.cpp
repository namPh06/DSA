#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , t;
    cin >>  n >> t;
    int a[10001] , f[10001];
    f[0] = 0 ;
    for(int i =  1;  i<= n ; i++){
        cin >> a[i];
    }
    for (int i = 1 ; i<= n ; i++){
        f[i] = f[i-1];
        if (a[i] > 0)
        f[i] += a[i];
    }
    while (t--){
        int l , r;
        cin >> l >> r;
        int ans = f[r] - f[l-1];
        if (ans > 0)
        cout << ans << endl;
        else cout << "0" << endl;
    }
    return 0;
}