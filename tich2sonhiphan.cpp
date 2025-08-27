#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll chuyendoi(string s) {
    ll x=0;
    for (auto z: s) {
        x = x * 2 + (z - '0');
    }
    return x;
}
int main()
{
    int t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << (ll)(chuyendoi(a)*chuyendoi(b)) << endl;
    }
}