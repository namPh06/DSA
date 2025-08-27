#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        string res = s;
        for  (int i = 1; i < s.size(); i++){
            if ((res[i-1] - '0') ^ 0 == s[i] - '0')
            res[i] = '0';
            else res[i] = '1';
        }
        cout << res << endl;
    }
    return 0;
}