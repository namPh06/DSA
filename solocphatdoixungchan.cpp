#include <bits/stdc++.h>
using namespace std;
bool check(string s){
    if (s.size() % 2 == 0)
    return true;
    return false;
    for (int i = 0 ; i < s.size() / 2 ; i++){
        if (s[i] != s[s.size() - i - 1])
        return false;s
    }
    return true;
}
void solve (int n){
    queue<string > q;
    q.push("6");
    q.push("8");
    while (n--){
        string s = q.front();
           q.pop();
        if (check(s))
        cout << s <<" ";
        q.push(s + "6");
        q.push(s+ "8");
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
