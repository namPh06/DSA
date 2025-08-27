#include <bits/stdc++.h>
using namespace std;
int a[1001], n, k;
vector<int> v;
int cnt = 0;

bool check() {
    for (int i = 1; i < k; i++) {
        if (v[a[i]-1] >= v[a[i+1]-1]) {
            return false;
        }
    }
    return true;
}

void inkq() {
    if (check()) {
        cnt++;
    }
}

void backtrack(int pos) {
    for (int i = a[pos-1] + 1; i <= n - k + pos; i++) {
        a[pos] = i;
        if (pos == k) {
            inkq();
        } else {
            backtrack(pos + 1);
        }
    }
}

int main() {
    cin >> n >> k;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    a[0] = 0;   
    backtrack(1);
    cout << cnt;
    return 0;
}