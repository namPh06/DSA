#include <bits/stdc++.h>
using namespace std;
int const mod = 1e9 + 7;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        vector <int > v(n+1,0);
        v[0] = 1;
        for (int i = 1; i <= n ;i++){
            for (int j = 1; j <= min(i,k); j++){
                v[i] = v[i] + v[i-j];
                v[i] %= mod;
            }
        }   
        cout << v[n]<< endl;
    }
    return 0;
}