#include <bits/stdc++.h>
using namespace std;
void solve (int n){
    queue<string > q;
    q.push("1");
    while (n--){
        string s = q.front();
        cout << s <<" ";
        q.pop();
        q.push(s + "0");
        q.push(s+"1");
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
