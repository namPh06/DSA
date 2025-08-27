#include <bits/stdc++.h>
using namespace std;
void backtrack(vector<vector<int>>& v, vector<int>& a, int n) {
    if (n < 1) return;
    vector<int> tmp(n - 1);
    for (int i = 0; i < n - 1; i++) {
        tmp[i] = a[i] + a[i + 1];
    }
    v.push_back(tmp);
    backtrack(v, tmp, n - 1);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> v;
        backtrack(v, a, n);
        for (int i = v.size() - 2; i >= 0; i--) {
            cout << "[";
            for (int j = 0; j < v[i].size(); j++) {
                if (j > 0) cout << " ";
                cout << v[i][j];
            }
            cout << "] ";
        }
        cout << "[";
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << "]\n";
    }
    return 0;
}
