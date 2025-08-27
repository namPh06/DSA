#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int const mod = 1e9 + 7;
void seive(){
    for (int i = 0 ; i <= 1000 ; i++){
        for (int j = 0; j <= 1000 ;j++){
            if (j == 0 || j == i)
            a[i][j] = 1;
            else a[i][j] = a[i-1][j-1] + a[i-1][j];
            a[i][j] %= mod;
        }
    }
}
int main(){
    seive();
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        cout << a[n][k] << endl;
    }
    return 0;
}