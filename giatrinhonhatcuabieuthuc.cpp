#include <bits/stdc++.h>
using namespace std;
bool cmp (int a, int b){
    return a > b;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n] , b[n];
        for (int i = 0; i < n ; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n ; i++){
            cin >> b[i];
        }
        sort (a, a + n);
        sort (b , b + n , cmp);
        long long res = 0;
        for (int i = 0; i < n ; i++){
            res += a[i] * b[i];
        }
        cout << res <<"\n";
    }
    return 0;
}