#include<bits/stdc++.h>
using namespace std;
int t, N, M;
vector<vector<int>> A;
vector<vector<bool>> visited;

int bfs() {
    visited.assign(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int steps = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [i, j] = q.front(); q.pop();
           if (i == N - 1 && j == M - 1) return steps;
            if (i + 1 < N) {
                int d = abs(A[i][j] - A[i + 1][j]);
                int ni = i + d;
                if (ni < N && !visited[ni][j]) {
                    visited[ni][j] = true;
                    q.push({ni, j});
                }
            }
            if (j + 1 < M) {
                int d = abs(A[i][j] - A[i][j + 1]);
                int nj = j + d;
                if (nj < M && !visited[i][nj]) {
                    visited[i][nj] = true;
                    q.push({i, nj});
                }
            }
            if (i + 1 < N && j + 1 < M) {
                int d = abs(A[i][j] - A[i + 1][j + 1]);
                int ni = i + d;
                int nj = j + d;
                if (ni < N && nj < M && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        steps++;
    }
    return -1;
}
int main() {
    cin >> t;
    while (t--) {
        cin >> N >> M;
        A.assign(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> A[i][j];
                cout << bfs() << "\n";
    }

    return 0;
}