#include <bits/stdc++.h>
using namespace std;
int a[31], n ,k;
vector <string > v;
void inkq(){
    string s = "";
    for (int i = 1 ;  i <= k ;i++){
        s += to_string (a[i]);
        if (i < k)
        s += " ";
    }
    v.push_back (s);
}
void backtrack (int pos){
    for (int i = a[pos - 1] + 1; i <= n - k + pos ; i++){
        a[pos ] = i;
        if (pos == k)
        inkq();
        else backtrack (pos + 1);
    }
}
int main(){
        cin >> n >> k;
        backtrack(1);
        sort (v.begin() , v.end());
        int cnt = 0;
        cout << v[0] << endl;
       for (int i = 1 ; i < v.size() ; i++){
        if (i*k >= v.size())
        break;
        cout << v[i*k] << endl;
       }
        return 0;
}