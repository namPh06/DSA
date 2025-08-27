#include <bits/stdc++.h>
using namespace std;
int a[20] , k , n ;
string s;
vector <char> v;
void inkq(){
    for (int i = 1; i<= k ; i++){
        cout << v[a[i]- 1]; 
    }
    cout << endl;
}
void backtrack (int pos){
    int start;
    if (pos == 1){
        start = 1;
    }
    else {
        start = a[pos - 1];
    }
    for (int i = start ; i <= n  ; i++){
        a[pos] = i;
        if (pos == k){
            inkq();
        }
        else backtrack(pos + 1);
    }
}
int main(){
   char t;
   cin >> t;
   cin >> k;
   s = "ABCDEFGHIJK";
   for (int i = 0 ; i < s.size(); i++){
   v.push_back (s[i]);
   if (s[i] == t)
   break;
   }
    n = v.size() ;
   backtrack(1);
   return 0;
}