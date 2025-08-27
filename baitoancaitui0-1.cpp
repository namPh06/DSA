#include <bits/stdc++.h>
using namespace std;

int F[1005][1005], N, M, A[1005], C[1005];

int qhd() {
    memset(F, 0, sizeof(F));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            F[i][j] = F[i - 1][j];
            if (j >= A[i - 1]) {
                F[i][j] = max(F[i][j], F[i - 1][j - A[i - 1]] + C[i - 1]);
            }
        }
    }
    return F[N][M];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) { 
            cin >> C[i];
        }
        cout << qhd() << endl;
    }
    return 0;
}
