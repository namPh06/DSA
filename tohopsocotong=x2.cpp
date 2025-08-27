#include <bits/stdc++.h>
using namespace std;
int a[21], n , k;
int b[1000];
int cnt = 0;
bool found = false;
bool found1 = false;
void inkq(int n){
    cout << "{";
    for (int i = 1; i <= n; i++){
        cout << b[i];
        if (i != n) cout <<" ";
    }
    cout << "}";
    cout << " ";
    found = true;
}
void backtrack(int i, int sum , int pos){
    for ( int j = pos; j < n ; j++){
        if (sum + a[j] <= k){
             b[i] = a[j];
            sum += a[j];
            if (sum == k)
            inkq(i);
            else backtrack(i + 1, sum , j);
            sum -= a[j];
        }
    }
} 
void backtrack2(int i, int sum , int pos){
    for ( int j = pos; j < n ; j++){
        if (sum + a[j] <= k){
             b[i] = a[j];
            sum += a[j];
            if (sum == k)
            {
                cnt++;
                found1 = true;
            }
            else backtrack2(i + 1, sum , j);
            sum -= a[j];
        }
    }
} 
int main(){
     int t;
     cin >> t;
     while (t--){
        cnt = 0;
        cin >> n >> k;
        for (int i = 0;  i< n ; i++){
            cin >> a[i];
        } 
        sort (a,a+n);
        found = false;
        found1 = false;
        backtrack2(1,0,0);
        if (found1  == true)
        cout << cnt <<" ";
        backtrack(1,0,0);
        if (!found)
            cout << "-1";
        cout << endl;
     }
     return 0;
}