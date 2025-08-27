#include <bits/stdc++.h>
using namespace std;
string check(string s) {
	stack<char> st;
	for (auto x : s) {
		if (x == ')') {
			bool ok = true;
			while (st.top() != '(') {
				char tmp = st.top();
				if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/')ok = false;
				st.pop();
			}
			if (ok)return "Yes";
			st.pop();
		}
		else st.push(x);
	}
	return "No";
}
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        cout << check(s) << endl;
    }
    return 0;
}