#include <bits/stdc++.h>
using namespace std;
int a[20] ,n , k;
vector <string> v1;
vector < int > v2;
void inkq(){
   string s ="";
   for (int i = 1; i <= k ; i++){
       s += to_string (v2[a[i] - 1]);
   }
   v1.push_back(s);
}
void backtrack(int pos){
    for (int i = a[pos - 1] + 1; i <= n- k + pos; i++){
        a[pos] = i ;
        if (pos == k)
        inkq();
        else backtrack (pos+1);
    }
}
// bool cmp(string a,string b){
//     if (a.size() != b.size())
//     return a.size() < b.size();
//     return a < b;
// }
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n ; i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }
    n = v2.size();
    backtrack(1);
    set < string > se;
    for (string k : v1){
        se.insert(k);
    }
    for (string it : se){
        cout << it << endl;
    }
    return 0;
}