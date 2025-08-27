#include <bits/stdc++.h>
using namespace std;
int a[101] = {0}, n , k;
vector <string > v;
void inkq(){
    for (int i = 1; i<= k ; i++){
        cout << v[a[i] - 1] <<" ";
    }
    cout << endl;
}
void backtrack (int pos ){
    for (int i = a[pos - 1] + 1; i<= n - k + pos ;i++){
        a[pos] = i ;
        if (pos == k)
        inkq();
        else backtrack (pos + 1);
    }
}
int main(){
    cin >> n >> k;
    set <string > se;
    for (int i = 0 ; i< n ; i++){
        string s;
        cin >> s;
        se.insert (s);
    }
    for (string x : se){
        v.push_back (x);
    }
    n = v.size();
    backtrack (1);
    return 0;
}