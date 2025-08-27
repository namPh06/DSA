#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    getline (cin,s);
    stack <int > st;
    int cnt = 1;
    for (int i = 0 ; i < s.size() ; i++){
        if (s[i] == '('){
            cout << cnt <<" ";
            st.push(cnt);
            cnt++;
        }
        else if (s[i] == ')') {
            cout << st.top() <<" ";
            st.pop();
        }
    }
    while (!st.empty()){
        st.pop();
    }
}
int main(){
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
         solve();
         cout << endl;
    }
    return 0;
}