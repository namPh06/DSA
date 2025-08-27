#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
struct matran{
    long long a[10][10];
}
matran operator *(matran x, matran y){
    matran z;
    for (int i =0 ; i < n ; i++){
        for (int j = 0; j < n ; j++){
            z.a[i][j] = 0;
            for (int k = 0 ; k < n ; k++){
                z.a[i][j] += (x.a[i][k] % mod) * (y.a[k][j] % mod ) % mod;
                z.a[i][j] %= mod;
            }
        }
    }
    return z;
}
matran matpow(matran x , int exp){
    if (exp == 1)
    return x;
    if (exp % 2 == 0){
        matran y = matpow(x,exp/2);
        return y*y;
    }
    return x*matpow(x,exp - 1);
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int k;
        cin >> n >> k;
        matran mat;
        for (int i = 0; i < n ; i++){
            for (int j = 0; j < n ; j++)
            cin >> a[i][j];
        }
        matran res = matpow(mat,k);
        long long ans = 0;
        for (int i = 0; i < n ; i++){
            ans += res.a[n-1][i];
            ans %= mod;
        }
        cout << ans <<"\n";
    }
    return 0;
}