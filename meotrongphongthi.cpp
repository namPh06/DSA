#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    map <int,vector <int >> mp;
    for (int i = 1; i<= n ; i++){
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    for (auto it : mp){
        cout << it.first <<": ";
        for (auto x : it.second){
            cout << x <<" ";
        }
        cout <<"\n";
    }
}