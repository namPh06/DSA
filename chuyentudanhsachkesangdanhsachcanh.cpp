#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    vector<pair<int, int>> v;

    for (int i = 1; i <= n; ++i) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int j;
        while (ss >> j) {
            if (i < j) {
                v.push_back({i, j});
            }
        }
    }

    sort(v.begin(), v.end());

    for (auto it : v) {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}
