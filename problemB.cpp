#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, x;
        cin >> n >> x;

        if (n == 1) {
            if (x == 0) cout << -1 << '\n';
            else cout << x << '\n';
        } else if (n == 2) {
            if (x == 0) cout << -1 << '\n';
            else cout << x + 2 << '\n'; // minimal with two positive integers
        } else {
            // For n >= 3
            long long a = 1LL << 17; // some big number
            long long b = 1LL << 18;
            long long temp = x ^ a ^ b;
            if (temp == a || temp == b || temp == 0) {
                // if conflict, choose other large numbers
                a = 1LL << 19;
                b = 1LL << 20;
                temp = x ^ a ^ b;
            }
            // Total sum is (n - 3)*1 + a + b + temp
            cout << (n - 3) * 1 + a + b + temp << '\n';
        }
    }
    return 0;
}
