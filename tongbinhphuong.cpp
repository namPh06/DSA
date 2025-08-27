#include <bits/stdc++.h>
using namespace std;
long long solve(int n){
    int i , j , f[10002];
    f[1] = 1 ; f[2] = 2 ; f[3] = 3;
    for (int i = 4; i<= 10000; i++){
        f[i] = i;
        for (int j = 1 ; j<= sqrt(i) ;j++)
        f[i] = min(f[i],f[i - j* j] + 1);
    }
    return f[n];
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << solve(n)<< endl;
    }
    return 0;
}