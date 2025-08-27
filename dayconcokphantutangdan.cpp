#include <bits/stdc++.h>
using namespace std;
int a[1001] , n , k;
vector <int > v;
void inkq(){
    for (int i = 1 ; i <= k ; i++){
        cout << v[a[i] - 1]  <<" ";
    }
    cout << endl;
}
void backtrack(int pos){
    for (int i = a[pos - 1] + 1; i<= n- k + pos; i++){
        a[pos] = i ;
        if (pos == k)
        inkq();
        else backtrack (pos+1);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
    v.clear();
    cin >> n >> k;
    int x;
    set < int > se;
    for (int i = 0 ; i < n ; i++){
        cin >> x;
        se.insert (x);
    }
    for (auto it : se){
        v.push_back(it);
    }
    n = v.size();
    backtrack (1);
    }
    return 0;
}