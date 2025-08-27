#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
    stack <int > st;
    long long n;
    cin >> n;
    while ( n != 0){
        st.push(n%2);
        n /= 2;
    }
    while (!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
}
    return 0;
}