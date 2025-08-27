#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& A, int n) {
    int l = 0, r = n - 1;
    while (l < n - 1 && A[l] <= A[l + 1]) l++;
    // if (l == n - 1) {
    //     cout << "0 0\n"; 
    //     return;
    // }
    while (r > 0 && A[r] >= A[r - 1]) r--;
    int subMin = *min_element(A.begin() + l, A.begin() + r + 1);
    int subMax = *max_element(A.begin() + l, A.begin() + r + 1);
    while (l > 0 && A[l - 1] > subMin) l--;
    while (r < n - 1 && A[r + 1] < subMax) r++;
    cout << l + 1 << " " << r + 1 << endl;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        solve(A, n);
    }
    return 0;
}
