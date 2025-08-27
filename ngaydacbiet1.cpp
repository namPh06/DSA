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
bool check(string s){
    if ((s[0] == '0' && s[1] == '0')|| s[2] == '2' || s[4] =='0' || (s[2] =='0' && s[3]=='0'))
    return false;
    return true;
}
string chen(string s){
    string res = s;
    res.insert(2,"/");
    res.insert(5,"/");
    return res;
}
int main(){
    backtrack(1);
    set <string > se;
    for (string x : v){
        if (check(x))
        se.insert(chen(x));
    }
    for (string x : se){
        cout << x << endl;
    }
    return 0;
}
