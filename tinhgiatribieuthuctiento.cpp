#include <bits/stdc++.h>
using namespace std;
long long cal(char s , long long a,long long b){
    if (s == '+') return a + b;
    if (s == '-') return a - b;
    if (s == '*') return a * b;
    else  return a / b;
}
void solve(){
    string s;
    cin >> s;
    stack <long long > st;
    for (int i = s.size() - 1; i >= 0 ; i--){
        if (isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else {
            long long a = st.top();
            st.pop();
            long long b = st.top();
            st.pop();
            st.push(cal(s[i] ,a ,b ));
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