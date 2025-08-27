#include <bits/stdc++.h>
using namespace std;
long long solve(long long n){
    queue <long long > q;
    q.push(1);
    int cnt = 0;
    while (!q.empty()){
        long long x = q.front();
        q.pop();
        if (x <= n) cnt++;
        q.push(x*10);
        q.push(x*10 + 1);
        if (x > n)
        break;
    }
    return cnt;
}
int main(){
    int t;
    cin >>  t;
    while (t--){
        long long n;
        cin >> n;
        cout << solve(n)<< endl;
    }  
    return 0;
}