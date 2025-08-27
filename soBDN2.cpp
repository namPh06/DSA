#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    queue <long long > q;
    q.push(1);
    while (!q.empty()){
        long long x = q.front();
        q.pop();
        if (x % n == 0){
            cout << x;
            break;
        }
        q.push(x*10);
        q.push(x*10 + 1);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
      int n;
      cin >>n;
      solve(n);
      cout << endl;
    }
    return 0;
}