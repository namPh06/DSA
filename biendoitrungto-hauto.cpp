#include <bits/stdc++.h>
using namespace std;
int pre(char c ){
    if (c == '(')
    return 0;
    else if ( c == '+' || c == '-')
    return 1;
    else if (c == '*' || c == '/')
    return 2;
    else return 3;
}
void solve(string s){
    string ans = "";
    stack <char > st;
    for (int i = 0 ; i < s.size() ; i++){
        if (isalpha(s[i])){
            ans += s[i];    
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            while (!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && pre(st.top()) >= pre(s[i])){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}