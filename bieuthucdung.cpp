#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int a = 0 , b = 0 ;
        int res = 0;
        for (int i =0 ;  i < s.length(); i++){
            if (s[i] == '[')
            a++;
            else b++;
            if (b > a){
                for (int j = i + 1 ; j < s.length() ; j++){
                    if (s[i] != s[j]){
                        res += j - i;
                        a++; b--;
                        swap (s[i] , s[j]);
                        break;
                    }
                }
            }
        }
        cout << res <<"\n";
    }
    return 0;
}