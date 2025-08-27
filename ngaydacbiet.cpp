#include <bits/stdc++.h>
using namespace std;
int a[10];
vector <string > v;
void inkq(){
    string s = "";
    for (int i = 1 ;  i <= 8 ;i++){
        s += to_string (a[i]);
    }
    v.push_back (s);
}
void backtrack(int pos) {
    for (int i = 0; i <= 2; i += 2) {
        a[pos] = i;
        if (pos == 8) {
            inkq();
        } else {
            backtrack(pos + 1);
        }
    }
}
string daochuoi(string s){
    string res = s;
    reverse(res.begin() , res.end());
    return res;
}
int main(){
    backtrack(1);
    set <string > se;
    vector <string > v1;
    for (string x :  v){
       v1.push_back(daochuoi(x));
    }
    for (int i = 0 ; i< v.size(); i++){
        if (v[i] == v1[i])
        se.insert(v[i]);
    }
    for (string x : se){
        cout << x <<" ";
    }
    return 0;
}
