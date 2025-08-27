#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int ans = 0;
        while (1){
            int x = s.find("()");
            if (x == -1)
            break;
            else{
                ans += 2;
                s.erase (x,2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}