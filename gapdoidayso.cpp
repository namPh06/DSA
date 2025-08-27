#include <bits/stdc++.h>
using namespace std;
long long solve (long long k ,long long x){
    if (k % 2 == 1)
    return x;
    else return solve(k / 2 , x + 1);
}
int main(){
    int t;
    cin >> t;
    while (t--){
        long long n, k;
        cin >> n >> k;
        cout << solve(k , 1) << endl;
    }
    return 0;
}
