#include <bits/stdc++.h>
using namespace std;
string chuyenhoa(int n) {
    string s ="";
    if (n == 0) {
       s += "0";
    }
    vector<int> v;
    while (n > 0) {
        v.push_back(n % 2);
        n = n / 2;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        s += to_string(v[i]);
    }
    return s;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << chuyenhoa(n)<<"\n";
    }
    return 0;
}