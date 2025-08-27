#include <bits/stdc++.h>
using namespace std;
int qhd(int C, int N, int A[]) {
    vector<int> F(C + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = C; j >= A[i]; j--) {
            F[j] = max(F[j], F[j - A[i]] + A[i]);
        }
    }
    return F[C];
}
int main() {
    int C, N;
    cin >> C >> N;
    int A[100]; 
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << qhd(C, N, A);
    return 0;
}