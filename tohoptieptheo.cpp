#include <bits/stdc++.h>
using namespace std;
int a[25], n , k;
vector <string > v;
void inkq(){
    string s = "";
    for (int i = 1 ; i <= k ; i++){
        s += to_string (a[i]);
    }
    v.push_back (s);
}
void backtrack (int pos ){
    for (int i = a[pos- 1] + 1 ;  i <= n - k + pos ; i ++ ){
        a[pos] = i ;
        if (pos == k)
        inkq();
        else backtrack (pos + 1);
    }
}
int main(){
    int t;
    cin >> t;
    map<int,bool> mp;
    while (t--){
        v.clear();
        mp.clear();
        cin >> n >> k;
        backtrack(1);
        sort (v.begin() , v.end());
        int b[25];
        string ans ="";
        for (int i = 0 ; i < k ; i++){
            cin >> b[i];
            ans += to_string (b[i]);
        }
        if (ans == v[v.size() - 1]){
            cout << k << endl;
        }
        else {
        for (int i = 0 ; i < ans.size();i++){
            mp[ans[i]] = true;
        }
        string res;
        for (int i = 0 ; i < v.size() ; i++){
            if (ans == v[i]){
                res = v[i + 1];
                break;
            }
        }
        int cnt = 0;
        for (int i = 0 ; i < res.size() ;i++){
            if (mp[res[i]])
            cnt++;
        }
        cout << (int)res.size() - cnt << endl;
        }
    }
    return 0;
}