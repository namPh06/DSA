#include <bits/stdc++.h>
using namespace std;
long long cal(string s , long long a , long long b){
    if ( s == "+")
    return a + b;
    if (s == "-")
    return a - b;
    if (s == "*")
    return a * b;
    if (s == "/")
    return a / b;
}
void solve(){
    string s;
    cin >> s;
    stack < long long > st;
    for (int i = s.size() - 1; i >= 0; i--){
        
    }
}