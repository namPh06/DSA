#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    // Count current good pairs
    int current_pairs = 0;
    for (int i = 0; i < n/2; i++) {
        if (s[i] == s[n-1-i]) {
            current_pairs++;
        }
    }
    
    // Count 0s and 1s
    int zeros = 0, ones = 0;
    for (char c : s) {
        if (c == '0') zeros++;
        else ones++;
    }
    
    // Maximum possible pairs is n/2
    if (k > n/2) {
        cout << "NO\n";
        return;
    }
    
    // If we need to increase pairs
    if (k > current_pairs) {
        int needed_pairs = k - current_pairs;
        // We need to make pairs by swapping characters
        // Each new pair requires 2 characters to be swapped
        if (needed_pairs * 2 <= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    // If we need to decrease pairs
    else if (k < current_pairs) {
        int pairs_to_break = current_pairs - k;
        // We can break pairs by swapping characters
        if (pairs_to_break <= n/2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    // If we already have exactly k pairs
    else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}