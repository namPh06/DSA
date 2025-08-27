#include <bits/stdc++.h>
using namespace std;
void solve (){
    int n;
    cin >> n;
    queue < long long > q;
    q.push(9);
    while (!q.empty()){
        long long x  = q.front();
        q.pop();
        if (x  %  n == 0){
            cout << x << "\n";
            break;
        }
        q.push(x*10 + 0);
        q.push(x*10 + 9);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}