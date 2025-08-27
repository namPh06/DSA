#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    // Convert string to integer
    int year = stoi(s);
    
    // Try all possible splits of the 4-digit number
    for (int i = 0; i <= 4; i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        
        // Skip if either part is empty
        if (left.empty() || right.empty()) continue;
        
        int a = stoi(left);
        int b = stoi(right);
        
        // Check if (a+b)^2 equals the year
        if ((a + b) * (a + b) == year) {
            cout << a << " " << b << "\n";
            return;
        }
    }
    
    // If no solution found
    cout << "-1\n";
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