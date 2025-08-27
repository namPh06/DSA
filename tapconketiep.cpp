#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int x[1005];
        for (int i = 0; i < k; i++) {
            cin >> x[i];
        }
        int i = k - 1;
        while (i >= 0 && x[i] == n - k + i + 1) {
            i--;
        }

        if (i < 0) {
            for (int j = 1; j <= k; j++) {
                cout << j << " ";
            }
        } else {
            x[i]++;
            for (int j = i + 1; j < k; j++) {
                x[j] = x[j - 1] + 1;
            }
            for (int j = 0; j < k; j++) {
                cout << x[j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
