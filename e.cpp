#include <iostream>
#include <vector>

using namespace std;

long long fibo(long long n) {
    if (n == 1 ) return 1;
    
    vector<long long> v = {1, 2};
    while (v.back() <= n) {
        long long tmp = v[v.size() - 1] + v[v.size() - 2];
        v.push_back(tmp);
    }
    
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == n) {
            return n;
        }
    }
    
    long long res = n;
    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i] < n) {
            res = n - v[i];
            break;
        }
    }

    return res;
}

int main() {
    long long n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}