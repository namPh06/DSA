#include <bits/stdc++.h>
using namespace std;
bool check (string s){
    for (int i = 0 ; i < s.size() - 1 ; i++){
        if (abs (s[i+1] - s[i]) >= 2)
        return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int res = 1;
    while (true){
        if (check(to_string (res))){
            cnt++;
            if (cnt == n){
                cout << res;
                break;
            }
        }
        res++;
    }
    return 0;
}