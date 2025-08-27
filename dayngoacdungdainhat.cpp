#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        stack <int > st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size() ; i++){
            if (s[i] == '(')
            st.push(i);
            else {
                st.pop();
                if (st.size() > 0){
                    ans = max (ans, i - st.top());
                }
                if (st.empty())
                st.push(i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}