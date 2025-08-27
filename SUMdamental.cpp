#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        if (n == 1) {
            if (x == 0) {
                cout << "0\n";
            } else {
                cout << x << "\n";
            }
        } else if (n == 2) {
            if (x == 0) {
                cout << "2\n";
            } else {
                // For n=2, we need two positive numbers that XOR to x
                // Let's try to find the smallest possible sum
                long long a = 1;
                while ((a ^ (a + 1)) != x) {
                    a++;
                    if (a > x + 2) {
                        a = -1;
                        break;
                    }
                }
                if (a == -1) {
                    cout << "-1\n";
                } else {
                    cout << (2 * a + 1) << "\n";
                }
            }
        } else {
            if (x == 0) {
                cout << n << "\n";
            } else {
                // For n >= 3, we can use [1, x, 1, 1, ..., 1]
                cout << (x + n - 1) << "\n";
            }
        }
    }
    
    return 0;
}
