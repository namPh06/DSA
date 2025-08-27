#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   int a[1001], f[1001] , ans = 0;
   for (int i = 0 ; i< n ; i++){
       cin >> a[i];
   }
   for (int i = 0 ; i < n ; i++){
    f[i] = 1;
    for (int j = 0 ; j < i ; j++){
        if (a[j] < a[i]){
            f[i] = max(f[i] ,f[j] + 1);
        }
    }
    ans = max (ans , f[i]);
   }
   cout << ans;
   return 0;
}