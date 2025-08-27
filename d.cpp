#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    multiset < int , greater <int >> se;
    for (auto x : a){
        auto it = se.upper_bound (x);
        if (it !=  se.end()){
            se.erase (it);
        }
        se.insert (x);
    }
    cout << se.size() <<"\n";
    return 0;
}