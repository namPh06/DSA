#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin >> t;
   while (t--){
    int n ;
    cin >> n;
    string s;
    cin >> s;
    bool ok = next_permutation(s.begin(), s.end());
    if (ok == false){
        cout << n <<" "<<"BIGGEST"<< endl;
    }
    else {
        cout << n <<" ";
        for (int i = 0 ; i < s.size() ; i++){
            cout << s[i];
        }
        cout << endl;
    }
   }
   return 0;
}