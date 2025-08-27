#include <bits/stdc++.h>
using namespace std;
int a[20], n, k;
vector<string> v;
char b[20];

void chuyenhoa() {
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0)
            b[i] = 'A';
        else 
            b[i] = 'B';
    }
}

void inkq() {
    chuyenhoa();
    string s = "";
    for (int i = 1; i <= n; i++) {
        s += b[i];
    }
    v.push_back(s);
}

void backtrack(int pos) {
    for (int i = 0; i <= 1; i++) {
        a[pos] = i;
        if (pos == n)
            inkq();
        else 
            backtrack(pos + 1);
    }
}

bool check(string s) {
    int cnt = 0;
    int total = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            cnt++;
        } else {
            if (cnt == k) {
                total++;
            }
            cnt = 0;
        }
    }
    if (cnt == k) {
        total++;
    }
    
    return total == 1;
}

int main() {
    cin >> n >> k;
    backtrack(1);
    int cnt2 = 0;
    for (string x : v) {
        if (check(x)) {
            cnt2++;
        }
    }
    cout << cnt2 << endl;
    for (string x : v) {
        if (check(x))
            cout << x << endl;
    }
    return 0;
}