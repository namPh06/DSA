#include <bits/stdc++.h>
using namespace std;
long long sum (int n){
    int tong = 0;
    while (n!= 0){
        tong += n % 10;
        n /= 10;
    }
    return tong;
}
long long solve (int n){
    queue < long long > q;
    q.push(4);
    q.push (7);
    while (!q.empty()){
        long long x = q.front() ;
        q.pop();
        if (sum (x) == n){
            return x;
            break;
        }
        q.push(x*10 + 4);
        q.push(x*10 + 7);
    }
    return -1;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << solve (n) <<"\n";
    }
    return 0;
}