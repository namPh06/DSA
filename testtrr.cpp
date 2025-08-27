#include<bits/stdc++.h>
using namespace std;
void solve1(const vector<vector<int>>& v, int n, ostream& out) {
    for (int i = 0; i < n; i++) {
        int in = 0;
        int out = 0;        
        for (int j = 0; j < n; j++) {
            if (v[j][i] == 1) in++;
        }
        
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) out++;
        }        
        cout << in << " " << out << endl;
    }
}

void solve2(const vector<vector<int>>& v, int n, ostream& out) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) m++;
        }
    }
    vector<vector<int>> v1(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                if (v[i][j] == 1) {
                    v1[i][cnt] = 1;  
                    v1[j][cnt] = -1; 
                    cnt++;
            }
        }
    }
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v1[i][j] << " ";
        }
        cout << endl;           
    }
}

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, n;
    cin >> t >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    if (t == 1) {
        solve1(v, n, cout);
    } else {
        solve2(v, n, cout);
    }
    return 0;
}