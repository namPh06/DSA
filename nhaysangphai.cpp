#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int h[MAX], jump_count[MAX], next_higher[MAX];
int N, Q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> h[i];
    stack<int> st;
    vector<int> right(N + 1, 0), left(N + 1, 0);
for (int i = N; i >= 1; i--) {
        while (!st.empty() && h[i] >= h[st.top()]) st.pop();
        if (!st.empty()) right[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = 1; i <= N; i++) {
        while (!st.empty() && h[i] >= h[st.top()]) st.pop();
        if (!st.empty()) left[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= N; i++) {
        if (right[i]) next_higher[i] = right[i];
        else next_higher[i] = left[i];
    }
    for (int i = N; i >= 1; i--) {
        int to = next_higher[i];
        if (to == 0) jump_count[i] = 0;
        else jump_count[i] = 1 + jump_count[to];
    }
    while (Q--) {
        int x;
        cin >> x;
        cout << jump_count[x] << '\n';
    }

    return 0;
}
