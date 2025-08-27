#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        int res = 0;
        int sum = 0;
        for (int i = 0 ;i < n ; i++){
            sum += a[i];
            if (sum <= 0 )
            sum = 0;
            res = max (res , sum);
        }
        cout << res << endl;
    }
    return 0;
}
