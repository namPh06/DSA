#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        cout << s[0];
        for(int i = 1; i < s.size() ; i++){
            int tmp = (s[i] - '0') ^ (s[i-1] - '0');
            cout << tmp;
        }
        cout << endl;
    }
    return 0;
}