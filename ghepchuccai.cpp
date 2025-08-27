#include <bits/stdc++.h>
using namespace std;

int a[20], n, used[20];
vector<char> v1;
vector<string> v;

bool check(string s) {
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == 'A' || s[i] == 'E') {
            if ((s[i-1] != 'A' && s[i-1] != 'E') && 
                (s[i+1] != 'A' && s[i+1] != 'E')) {
                return false;
            }
        }
    }
    return true;
}

void inkq() {
    string s = "";
    for (int i = 1; i <= n; i++) {
        s += v1[a[i] - 1];
    }
    if (check(s)){ 
        v.push_back(s);
    }
}
void backtrack(int pos) {
    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) {
            a[pos] = i;
            used[i] = 1;
            if (pos == n) {
                inkq();
            } else {
                backtrack(pos + 1);
            }
            used[i] = 0;
        }
    }
}

int main() {
    char k;
    cin >> k;
    string t = "ABCDEFGH";
    for (int i = 0; i < t.size(); i++) {
        v1.push_back(t[i]);
        if (t[i] == k) break;
    }
    n = v1.size(); 
    backtrack(1);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    
    return 0;
}