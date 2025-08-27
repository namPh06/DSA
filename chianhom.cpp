#include <bits/stdc++.h>
using namespace std;
int a[201],n;
bool check = false;
void backtrack(int sum, int i , int k){
    for(int j = 0 ; j< n ; j++){
        if (sum + a[j] == k){
            check = true;
             break;
        }
        else if (sum + a[j] < k)
        backtrack(sum + a[j] , j , k);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        int sum = 0;
        for (int i = 0 ; i < n ; i++){
            cin >> a[i];
            sum += a[i];
        }
         if (sum % 2 != 0){
            cout <<"NO\n";
         }
         else {
            backtrack(0,0,sum/2);
            if (check == true)
            cout <<"YES\n";
         }
    }
    return 0;
}