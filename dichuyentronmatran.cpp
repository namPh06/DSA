#include <bits/stdc++.h>
using namespace std;
int Cnt(int n,int k){
    if ( k == 0 || k == n)
    return 1;
    return Cnt(n-1,k-1) + Cnt(n-1,k);
}    
int main(){
    int t;
    cin >> t;
    while (t--){
        int m,n;
        cin >> m >> n;
        int a[201][201];
        for (int i = 0 ; i<m;i++){
            for (int j = 0 ; j< n ;j++)
            cin >> a[i][j];
        }
        cout << Cnt(m+n -2, n-1)<< endl;
    }
    return 0;
}