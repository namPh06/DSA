#include <bits/stdc++.h>
using namespace std;
vector < string > v;
void backtrack(string b, int n){
    if (b.size() == n){
        string a = b;
        reverse (a.begin() , a. end());
        v.push_back(b + a);
        return;
    }
    b.push_back('6');
    backtrack(b,n);
    b.pop_back();
    b.push_back('8');
    backtrack(b,n);
    b.pop_back();
}
bool cmp(string a, string b){
    if (a.size() == b.size())
    return a < b;
    return a.size() < b.size();
}
void sang(){
    int i = 1;
    while (v.size() < 10000){
        backtrack("", i);
        i += 1;
    }
}
int main(){
    int t;
    cin >> t;
    sang();
    sort (v.begin() , v.end() , cmp);
    while (t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cout << v[i]<<" ";
        }
        cout <<"\n";
    }
    return 0;
}