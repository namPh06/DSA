#include <bits/stdc++.h>
using namespace std;
int main(){
        cin.tie(0) -> sync_with_stdio(0);
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n ; i++){
            cin >> a[i];
        }
        sort (a, a + n);
        int res = 0;
        for (int i = 0;  i < n; i++){
            if (a[i] != a[n-1]){
                res = max (res, a[i]);
            }
        }
        cout << res % a[n-1];
        return 0;
}