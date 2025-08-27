#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 500;
int primeExp[MAXN + 1];
bool isPrime[MAXN + 1];
vector<int> primes;
void sieve() {
    fill(isPrime, isPrime + MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAXN; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= MAXN; j += i)
                isPrime[j] = false;
        }
    }
}
int countPrimeInFactorial(int n, int p) {
    int cnt = 0;
    while (n) {
        cnt += n / p;
        n /= p;
    }
    return cnt;
}
ll countDivisors(int n, int k) {
    map<int, int> expo;
    for (int p : primes) {
        int e = countPrimeInFactorial(n, p) -
                countPrimeInFactorial(k, p) -
                countPrimeInFactorial(n - k, p);
        if (e > 0)
            expo[p] = e;
    }
    ll res = 1;
    for (auto [p, e] : expo) {
        res *= (e + 1); 
    }
    return res;
}

int main() {
    sieve(); 
    int n, k;
    while (cin >> n >> k) {
        cout << countDivisors(n, k) << '\n';
    }
    return 0;
}
