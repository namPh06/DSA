#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n,s;
        cin >> n >> s;
        int a[201];
        for (int i = 0; i < n ; i++){
            cin >> a[i];
        }
        vector <bool > v(s+1,false);
        v[0] = true;
        for (int i = 0; i < n ; i++){
                for (int j = s;  j >= a[i] ; j--){
                    if (v[j - a[i]] == true){
                        v[j] = true;
                    }
                }
        }
        if (v[s] == true)
        cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}