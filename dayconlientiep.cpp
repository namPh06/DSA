#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , a[100001];
    cin >> n ;
    int m = - 1,  cnt = 0 , ans = 0 ;
    for (int i = 0; i < n ; i++){
        cin >> a[i];
    } 
    for (int i = 0 ; i< n ; i++){
        m = max(m, a[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if (a[i] == m){
        cnt++;}
    else {
        ans = max(cnt, ans);
        cnt = 0 ;
    }
   }
   cout << max (ans , cnt);
   return 0;
}