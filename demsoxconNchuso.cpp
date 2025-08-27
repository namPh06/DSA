TR#include <bits/stdc++.h>
using namespace std;
long long n , ans;
int const mod  = 1e9 + 7;
void backtrack (int pos, int start , int n){
      if (pos == n){
        ans = (ans + 1) % mod;
        return;
      }
      for (int i = start ; i <= 9 ; i++){
        backtrack(pos + 1, i , n);
      }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        ans = 0;
        backtrack(0,0,n);
        cout << ans << endl;
    }
    return 0;
}