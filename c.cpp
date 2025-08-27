#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0 ; i < s.size() ; i++){
        if (s[i] == 'A'){
            for (int j = s.size() - 1; j >= i ; j--){
                if (s[j] =='Z'){
                    res = max (res, j - i + 1);
                    break;
                }
            }
        }
    }
    cout << res;
}