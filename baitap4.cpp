#include <bits/stdc++.h>
using namespace std;
int a[20] , n , k;
vector <long long > v;
set <string > se;
void inkq(){
    string s ="";
    for (int i = 1 ; i <= k ; i++){
        s += to_string( v[a[i]- 1] );
    }
    se.insert(s);
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
    int b[20]; 
    for (int i = 0; i< n ; i++){
          cin >> b[i];
          v.push_back(b[i]);
    }
    n = v.size();
    backtrack(1);
    for (auto it : se){
        cout << it << endl;
    }
    return 0;
}