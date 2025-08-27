#include <bits/stdc++.h>
using namespace std;
int a[11], n;
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
int main(){
     int t;
     cin >> t;
     while (t--){
        cin >> n;
        backtrack(1,0,n);
        cout << endl;
     }
     return 0;
}