#include <bits/stdc++.h>
using namespace std;
int a[20] , n , used[20]; 
vector < char > v;
void inkq(){
    for (int i = 1; i<= n ; i++){
        cout << v[a[i] - 1];
    }
    cout <<" ";
}
void backtrack (int pos ){
    for (int i = 1 ; i<= n ; i++){
        if (used[i] == 0){
            a[pos ] = i;
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
        string s;
        cin >> s;
        v.clear();
        for (int  i = 0 ; i< s.size(); i++){
            v.push_back (s[i]);
        }
        n = v.size();
        backtrack(1);
        cout << endl;
    }
    return 0;
}