#include <bits/stdc++.h>
using namespace std;
int a[11], n;
int cnt = 0;
void inkq(int n){
    cout << "(";
    for (int i = 1; i< n ; i++){
        cout << a[i]<<" ";
    }
    cout << a[n]<<")";
    cout <<" ";
}
void backtrack(int i, int sum , int k ){
    for (int j = k; j >= 1 ; j--){
        if (sum + j <= n){
            a[i] = j;
            sum += j;
            if (sum == n)
            inkq(i);
            else backtrack(i + 1, sum , j);
            sum -= j;
        }
    }
}
void backtrack2(int i, int sum , int k ){
    for (int j = k; j >= 1 ; j--){
        if (sum + j <= n){
            a[i] = j;
            sum += j;
            if (sum == n)
            cnt++;
            else backtrack2(i + 1, sum , j);
            sum -= j;
        }
    }
}
int main(){
     int t;
     cin >> t;
     while (t--){
        cnt = 0;
        cin >> n;
        backtrack2(1,0,n);
        cout << cnt << endl;
        backtrack(1,0,n);
        cout << endl;
     }
     return 0;
}