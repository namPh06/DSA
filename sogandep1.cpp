#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    queue<long long> q;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        long long tmp = q.front();
        q.pop();
        cnt++;
        if (cnt == n) {
            cout << tmp << "\n";
            break;
        }
        int res = tmp % 10;
        for (int i = -1; i <= 1; i++) {
            int res1 = res + i;
            if (0 <= res1 && res1 <= 9) {
                long long tmp1 = tmp * 10 + res1;
                q.push(tmp1);
            }
        }
    }
    return 0;
}
