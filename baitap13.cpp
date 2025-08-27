#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,u,v;
    cin >> n >> u >> v;
    long long a[n+1];
    for (int i = 1; i<=n ;i ++){
        cin >> a[i];
    }
    long long sum = 0, res = -1e18;
    int len = 0;
    for (int i = 1; i<= n ; i++){
        sum += a[i];
        len++;
        if (len >= u && len <= v){
            res = max(res,sum);
        }
        if (sum <= 0){
            sum =0;
            len = 0;
        }
        
    }
    cout <<res;
    return 0;
}