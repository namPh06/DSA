#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n ; i++){
        cin >> a[i];
    }
    stack < int > st;
    for (int i = 0; i< n; i++){
        if (st.empty()){
            st.push(a[i]);
        }
        else {
            if ((st.top() + a[i]) % 2 == 0){
                st.pop();
            }
            else st.push(a[i]);
        }
    }
    cout << st.size();
    return 0;
}