#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    int cnt = 0;
    int cnt2 = 0;
    while (n > 0) {
        int tmp = n % 3;
        if (tmp == 2) cnt++;
        cnt2++;
        n /= 3;
    }
    return cnt > cnt2 / 2;
}

string chuyendoi(int n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s = to_string(n % 3) + s;
        n /= 3;
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<int> q;
        vector<int> result;
        q.push(1);
        q.push(2);
        while (result.size() < n && !q.empty()) {
            int current = q.front();
            q.pop();
            if (check(current)) {
                result.push_back(current);
            }
            
            if (result.size() < n) {
                q.push(current * 3);
                q.push(current * 3 + 1);
                q.push(current * 3 + 2);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << chuyendoi(result[i]);
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
