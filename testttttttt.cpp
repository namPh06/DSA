#include <bits/stdc++.h>
using namespace std;
bool check(string s){
   for (int i = 0 ; i<= s.size() / 2 ; i++){
    if (s[i] != s[s.size() - i - 1])
    return false;
   }
   return true;
}
int main(){
    string s;
    cin >> s;
    int t;
    cin >> t;
    while (t--){
        int l,r;
        cin >> l >> r;
        string tmp ="";
        for (int i = l ; i <= r; i++){
            tmp += s[i-1];
        }
        if (check(tmp))
        cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}