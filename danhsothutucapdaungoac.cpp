#include <bits/stdc++.h>
using namespace std;
void solve(string s){
    int n = s.size();
    stack < char > v;
    for (int i = 0; i < n ; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        v.push(i);
        else {
            char in  = v.top() , out = s[i];
            if (in == '(' && out ==')') 
            v.push(i);
            else if (in == '[' && out == ']')
            v.push(i);
            else if (in == '{' && out == '}')
            v.push(i)
        }
    }
     for (int x : v){
        cout << x <<" ";
     }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        solve(s);
        cout << endl;
    }
    return 0;
}