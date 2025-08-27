#include <bits/stdc++.h>
using namespace std;
vector<string > v;
void solve(int n) {
    queue<string> q;
    q.push("6");
    q.push("8");
    while (!q.empty()) {
        string x = q.front();
        q.pop();
        v.push_back(x);
        if (x.length() < n) {
            q.push(x + "6");
            q.push(x + "8");
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        v.clear();
        int n;
        cin >> n;
        solve(n);
        for (int i = v.size() - 1;  i >=  0;i--){
        	cout << v[i] <<" ";
		}
		cout << endl;
    }
    return 0;
}