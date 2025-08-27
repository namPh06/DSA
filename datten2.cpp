#include <bits/stdc++.h>
using namespace std;
string b = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, k ,a[20];
void inkq(){
    for (int i = 1; i <= k ; i++){
        cout << b[a[i]];
    }
    cout << endl;
}
void backtrack (int pos ){
    for (int i = a[pos - 1] + 1; i <= n - k + pos ; i++){
        a[pos] = i;
        if (pos == k)
        inkq();
        else backtrack (pos + 1);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        backtrack (1);
        cout << endl;
    }
    return 0;
}