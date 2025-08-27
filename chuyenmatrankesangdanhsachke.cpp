#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[1001][1001];
    vector<int> v[1001];
    for (int i = 1; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                v[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n ; i++) {
        for (int x : v[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
