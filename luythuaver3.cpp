#include <bits/stdc++.h>
using namespace std; 
long long mod = 1e6;
long long superpow(long long a, long long b ,long long m){
    if (b == 0) 
    return 1;
    long long r = superpow(a, b / 2 , m);
    r = (__int128)r * r % m;
    if (b % 2 == 1) 
    r = (__int128)r * a % m ;
    return r; 
}
string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}
int main(){
        long long a,b;
        cin >> a >> b;
        string t = to_string (superpow(a,b,mod));
        cout << t << endl;
        if (t.size() <= 6){
           cout << t ;
        }
        else {
            string tmp = "";
            int cnt = 0;
            for (int i = t.size() - 1 ; i >= 0; i--){
                tmp += t[i];
                cnt++;
                if (cnt == 6)
                break;
            }
            cout << reverseString(tmp);
        }
}