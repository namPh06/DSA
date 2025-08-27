#include <bits/stdc++.h>
using namespace std;
void solve(string s){
    stack <char > st;
    for (char x : s){
        if (!st.empty() && x == st.top()){
            st.pop();
        }
        else {
            st.push(x);
        }
    }
    string tmp = "";
    while (!st.empty()){
        tmp += st.top();
        st.pop();
    }
    string res ="";
    for (int i = tmp.size() - 1; i >= 0 ; i--){
        res += tmp[i];
    }
    if (res == "") 
    cout << "EMPTY" << endl;
    else cout << res << endl;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >>s;
        solve(s);
    }
    return 0;
}