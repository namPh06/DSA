#include <bits/stdc++.h>
using namespace std;
long long calc(string s, long long a, long long b) {
    if (s == "+") return a + b;
    if (s == "-") return a - b;
    if (s == "*") return a * b;
    if (s == "/") return a / b;
    return 0;
}
void Hauto(string a[], int n) {
    stack<long long> st;
    for (int i = 0; i < n; i++) {
        if (a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/") {
            long long b = st.top(); st.pop();
            long long c = st.top(); st.pop();
            st.push(calc(a[i], c , b));
        } else {
            st.push(stoll(a[i]));
        }
    }
    cout << st.top();
}
void Tiento(string a[], int n) {
    stack<long long> st;
    for (int i = n - 1; i >= 0 ; i--) {
        if (a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/") {
            long long b = st.top(); st.pop();
            long long c = st.top(); st.pop();
            st.push(calc(a[i], b,c));
        } else {
            st.push(stoll(a[i]));   
        }
    }
    cout << st.top();
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (a[0] == "+" || a[0] == "-" || a[0] == "*" || a[0] == "/" ){
            Tiento(a,n);
        }
        else {
            Hauto(a, n);
        }
        cout << endl;
    }
    return 0;
}
