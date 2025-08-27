#include <bits/stdc++.h>
using namespace std;
void backtrack (int a[] ,int n){
    if ( n < 1)
    return;
    int tmp[15];
    for (int i = 0 ; i < n - 1; i ++){
        tmp[i] = a[i] + a[i+1];
    }
    cout <<"[" <<a[0];
    for(int i = 1 ; i< n ; i++){
        cout << " "<<a[i];
    } 
    cout << "]";
    cout << endl;
    backtrack (tmp,n-1);
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[20];
        for (int i = 0 ; i< n ; i++){
            cin >> a[i];
        }
        backtrack(a,n);
        cout << endl;
    }
    return 0;
}