#include <bits/stdc++.h>
using namespace std;
bool check(long long n) {
    while (n != 0) {
        int digit = n % 10;
        if (digit != 0 && digit != 1) {
            return false;
        }
        n /= 10;
    }
    return true;
}
long long solve(int n) {
    queue<long long> q;
    q.push(1); 
    while (!q.empty()) {
        long long tmp = q.front();
        q.pop();        
        if ( tmp % n == 0) {
            return tmp;
        }
        q.push(tmp * 10);    
        q.push(tmp * 10 + 1); 
    }   
    return -1;
}
int main() {
    int t;
    cin >> t;    
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    
    return 0;
}
