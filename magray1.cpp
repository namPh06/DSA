#include <bits/stdc++.h>
using namespace std;
int a[20] , n ;
void inkq(){
    cout << a[1];
    for ( int i = 2 ; i <= n ; i++){
        int res = a[i] ^ a[i-1];
        cout << res;
    }
    cout <<" ";
}
void backtrack(int pos){
    for (int i = 0 ; i<= 1; i++){
        a[pos] = i;
        if (pos == n)
        inkq();
        else backtrack(pos + 1);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        backtrack(1);
        cout << endl;
    }
    return 0;
}