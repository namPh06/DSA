#include <bits/stdc++.h>
using namespace std;
int a[20] , n , used[20];
vector <string > v;
void inkq(){
    string s ="";
    for (int i = 1 ;i <= n ; i++){
        s += to_string(a[i]);
    }
    v.push_back (s);
}
void backtrack (int pos){
    for(int i = 1 ; i <= n ; i++){
     if (used[i] == 0){
        a[pos] = i;
        used[i] = 1;
        if (pos == n) 
        inkq();
        else backtrack (pos + 1);
        used[i] = 0;
       }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        v.clear();
        memset (used, 0 ,sizeof(used));
        backtrack(1);
        for (int i = v.size() - 1 ; i >= 0 ;i --){
            cout << v[i]<<" ";
        }
        cout << endl;
    }
    return 0;
}