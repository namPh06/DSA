#include <bits/stdc++.h>
using namespace std;

int a[20], n;

bool check() {
    if (a[0] != 8 || a[n - 1] != 6) 
        return false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 8 && a[i + 1] == 8)
            return false;
    }
    for (int i = 0; i < n - 3; i++) { 
        if (a[i] == 6 && a[i + 1] == 6 && a[i + 2] == 6 && a[i + 3] == 6)
            return false;
    }
    return true;
}

void inkq() {
    if (check()) {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
    }
}

void backtrack(int pos) {
    for (int i = 6; i <= 8; i += 2) {
        a[pos] = i;
        if (pos == n - 1) {
            inkq();
        } else {
            backtrack(pos + 1);
        }
    }
}

int main() {
    cin >> n;
    backtrack(0); 
    return 0;
}
