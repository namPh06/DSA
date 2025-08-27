#include <bits/stdc++.h>
using namespace std;
int a[20] , n , k;
// vector < string > vp;
set < string > vp;

vector <int > v;
void inkq(){
    string t = "";
    for (int i = 1; i<= k ; i++){
        t += to_string (v[a[i] - 1]);
    }
    vp.insert(t);
    // vp.push_back(t);
}
void backtrack (int pos){
    for (int i = a[pos - 1] + 1; i <= n - k + pos ;i++){
        a[pos] = i;
        if (pos == k)
        inkq();
        else backtrack(pos + 1);
    }
}
int main(){
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 1; i <= n ; i++ ){
        k = i;
        backtrack(1);
    }
   for (auto it : vp){
    cout << it << endl;
   }
    //  sort (vp.begin() , vp.end());
    //  for (int i = 0;  i < vp.size() ; i++){
    //     cout <<vp[i] << endl;
    //  }
    return 0;
}