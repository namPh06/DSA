#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        set < int > se;
        for (int i = 0; i < n ; i++){
            int x, y;
            char z;
            cin >> x >> y >> z;
            se.insert (x);
            se.insert(y);
        }
        for (auto it : se){
            cout << it <<" ";
        }
        cout << endl;
    }
    return 0;
}