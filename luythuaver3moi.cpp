#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e6;

long long binpow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    long long a, b;
    cin >> a >> b;
    long long res = binpow(a, b, MOD);
    if (a == 0) cout << 0;
    else if (b == 0) cout << 1;
    else if (a == 1) cout << 1;
    else if (b <= 20 && pow(a, b) < MOD) {
        cout << (long long)pow(a, b);
    } else {
        cout << setw(6) << setfill('0') << res;
    }

    return 0;
}
