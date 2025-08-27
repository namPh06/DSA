#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        stack < char > st;
        int cnt = 0;
        for (char c : s ){
            if ( c == '(')
            st.push(c);
            else {
                if (st.empty()){
                    cnt++;
                    st.push('(');
                }
                else st.pop();
            }
        }
        cout << cnt + st.size() / 2 << endl;
    }
    return 0;
}