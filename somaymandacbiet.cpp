#include <bits/stdc++.h>
using namespace std;
int check(string s, int n) {
    int r = 0;
    for (char x : s) {
        r = (r * 10 + x - '0') % n;
    }
    return r;
}
void solve() {
    int n;
    cin >> n;
    queue<string> q;
    q.push("6");
    q.push("8");
    while (!q.empty()) {
        string x = q.front();
        q.pop();
        if (x.size() > 200)
        break;
        if (check(x, n) == 0) {
            cout << x;
            return;
        }
        string s1 = x + "6";
        if (check(s1,n) == 0){
            q.push(s1);
        }
        string s2 = "8" + x;
        if (check(s2,n) == 0){
            q.push(s2);
        }
    }
    cout << "-1";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
    // int n;
    // cin >> n;
     solve();
     cout << endl;
    }
    return 0;
}
