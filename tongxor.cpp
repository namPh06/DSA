#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    while (q--){
        int x,y;
        cin >> x >> y;
        map <int,int > mp;
        for (int i = x; i <= y; i++){
            mp[a[i]]++;
        }
        vector <int > v;
        for (int i = x ; i <= y ; i++){
            if (mp[a[i]] % 2 == 0){
                v.push_back(a[i]);
            }
            mp[a[i]] = 1;
        }
        int sum = 0;
        for (int i = 0 ; i < v.size() ; i++){   
            sum ^= v[i];
        }
        cout << sum <<"\n";
    }
    return 0;
}