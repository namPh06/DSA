#include <bits/stdc++.h>
using namespace std;

long long calc(string s, long long a, long long b) {
    if (s == "+") return a + b;
    if (s == "-") return a - b;
    if (s == "*") return a * b;
    if (s == "/") return a / b;
    return 0;
}
void solve() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        string line;
        getline(cin, line);
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
        stack<long long> st;
        for (int i = n - 1; i >= 0; i--) {
            string tk = tokens[i];
            if (tk == "+" || tk == "-" || tk == "*" || tk == "/") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                st.push(calc(tk, a, b));
            } else {
                st.push(stoll(tk));
            }
        }
        cout << st.top() << endl;
    }
}
int main() {
    solve();
    return 0;
}
