#include <bits/stdc++.h>
using namespace std;
vector < int > v;
int n, k;
int a[1001];
bool ok , check[1001];
void backtrack (int cnt, int sum1 , int sum2){
    if (ok)
    return;
    if (cnt == k){
        ok = true;
        return;
    }
    for (int i = 0 ; i < n; i++){
        if (!check[i]){
            check[i] = true;
            if (sum1 == sum2/k){
                backtrack(cnt+1, 0 , sum2);
                return;
            }
            else if (sum1 < sum2 / k)
            backtrack(cnt , sum1 + a[i], sum2);
            else return;
        }
        check[i] = false;
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        ok = false;
        int sum1 = 0;
        for (int i = 0; i < n ; i++){
            cin >> a[i];
            sum1 += a[i];
            check[i] = false;
        }
        if (sum1 % k != 0) 
        cout << 0 << endl;
        else {
            backtrack( 0 , 0 , sum1 );
            if (ok)
            cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}