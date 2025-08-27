#include <bits/stdc++.h>
using namespace std;

int a[100], n;

void inkq() {
    index++; 
    if (index % 2 == 0) {
        cout << index << ": ";
        for (int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << endl;
    }
}

void backtrack(int j) {
    for (int i = 0; i <= 2; i++) {
        a[j] = i;
        if (j == n) {
            inkq();
        } else {
            backtrack(j + 1);
        }
    }
}

int main() {
    cin >> n;
    backtrack(1);
    return 0;
}
