#include <bits/stdc++.h>
using namespace std;
int check(string s){
    int n = s.size();
    stack < char > v;
    for (int i = 0; i < n ; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        v.push(s[i]);
        else {
            if (v.empty()) return 0;
            char in  = v.top() , out = s[i];
            if (in == '(' && out ==')') 
            v.pop();
            else if (in == '[' && out == ']')
            v.pop();
            else if (in == '{' && out == '}')
            v.pop();
            else return 0;
        }
    }
    return v.empty();
}
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        if (check(s))
        cout <<"true\n";
        else cout <<"false\n";
    }
    return 0;
}