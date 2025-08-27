#include <bits/stdc++.h>
using namespace std;
int a[101] = {0}, used[101], n;
vector <string > v;
string t;
bool check(){
    return v[a[1] - 1] == t;

}
void inkq(){
    if (check()){
     for (int i = 1; i <= n ;i++){
         cout << v[a[i] - 1] <<" " ;
     }
     cout << endl;
    }
}
void backtrack(int pos){
    for (int i = 1 ; i<= n ;i++){
        if (used[i] == 0){
            a[pos] = i ;
            used[i] = 1;
            if (pos == n)
            inkq();
            else backtrack(pos + 1);
            used[i] = 0;
        }
    }
}
int main(){
    cin >> n;
    set <string > se;
    string b[101];
    for (int i = 1 ; i <= n; i++){
        string x;
        cin >> x;
        se.insert(x);
    }
    cin >> t;
    for (string b : se){
        v.push_back(b);
    }
    n = v.size();
    backtrack(1);
    return 0;
}