#include <bits/stdc++.h>
using namespace std;
int quay(int a[] , int n){
    for (int i = 0 ; i < n - 1; i ++){
        if (a[i] > a[i+ 1])
        return i+1;
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0;  i < n ; i++){
            cin >> a[i];
        }
        cout << quay(a,n) << endl;
    }
    return 0;
}