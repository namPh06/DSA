#include <bits/stdc++.h>
using namespace std;
int a[20], n ,k;
vector <string > v;
void inkq(){
    string s = "";
    for (int i = 1 ;  i <= k ;i++){
        s += to_string (a[i]);
    }
    v.push_back (s);
}
void backtrack (int pos ){
    for (int i = a[pos - 1] + 1; i <= n - k + pos ; i++){
        a[pos ] = i;
        if (pos == k)
        inkq();
        else backtrack (pos + 1);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        v.clear();
        cin >> n >> k;
        int b[20];
        for (int i = 0 ; i< k ; i ++){
            cin >>b[i]; 
        }
        backtrack(1);
        sort (v.begin() , v.end());
    //    for (string x : v){
    //     cout << x <<" ";
    //    }
       string tmp ="";
        for (int i = 0 ; i <k ; i++ ){
            tmp += to_string(b[i]);
        }
        int cnt = 0;
        for (string x : v){
            cnt++;
            if (x == tmp)
            break;
        }
        cout << cnt << endl;
        //cout << tmp;
    }
    return 0;
}