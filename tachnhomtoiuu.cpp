#include <bits/stdc++.h>
using namespace std;

int minGroups(vector<int> &A, int K) {
    sort(A.begin(), A.end()); // Sắp xếp mảng
    int countGroups = 0;
    int i = 0, N = A.size();

    while (i < N) {
        int start = A[i];  // Chọn phần tử đầu tiên của nhóm mới
        countGroups++;
        while (i < N && A[i] - start <= K) i++; // Thêm vào nhóm nếu thỏa mãn điều kiện
    }

    return countGroups;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cout << minGroups(A, K) << endl;
    return 0;
}
