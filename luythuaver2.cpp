#include <bits/stdc++.h>
using namespace std;
long long superpow(long long a, long long b , long long c){
    if (b == 0) return 1 % c;
    long long r = superpow(a, b / 2, c);
    r = (__int128)r * r % c;
    if (b % 2 == 1) r = (__int128)r * a % c;
    return r; 
}

int main(){
    int t;
    cin >> t;
    while (t--){
        long long a, b, c;
        cin >> a >> b >> c;
        cout << superpow(a, b, c) << endl;
    }   
    return 0;
}
