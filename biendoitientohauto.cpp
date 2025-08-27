#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    stack <string > st;
    for (int i = s.size() - 1; i >= 0 ; i--){
        if (isalpha (s[i])){
            st.push (string (1,s[i]));
        }
        else {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string tmp = a + b + s[i];
            st.push(tmp);
        }
    }
    cout << st.top();
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
    return 0;
}