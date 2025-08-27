#include <bits/stdc++.h>
using namespace std;
int a[25], n ,k;
vector <string > v;
vector <int > v1;
bool check(){
    for (int i = 1 ;i <= k - 1 ; i++){
        if (v1[a[i] - 1] > v1[a[i + 1] - 1])
        return false;
    }
    return true;
}
void inkq(){
    if (check()){
        string s ="";
        for (int i =1; i <= k ; i++){
            s += to_string (v1[a[i] - 1]) + " ";
        }
        v.push_back(s);
    }
}
void backtrack(int pos){
    for (int i = a[pos - 1] + 1; i <= n - k + pos ; i++){
        a[pos] = i;
        if (pos == k)
        inkq();
        else backtrack(pos + 1);
    }
}
int main(){
    cin >> n;
    for (int i = 0; i < n ; i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 2; i <= n ; i++){
        k = i;
        backtrack(1);
    }
    sort (v.begin(), v.end());
    for (string x : v){
        cout <<x  <<"\n";
    }
    return 0;
}