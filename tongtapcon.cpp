#include <bits/stdc++.h>
using namespace std;
int a[21] , s , n , cnt = 0;
void backtrack(int pos ,int sum){
    if (sum == s && pos > 1)
    cnt++;
    for (int i = pos ; i <= n ; i++){
        if (sum + a[i] <= s)
        backtrack(i+1 , sum + a[i]);
    }
}
int main(){
    cin >> n >> s;
    for (int i = 1; i<= n ; i++){
        cin >> a[i];
    }
    backtrack(1,0);
    cout << cnt ;
    return 0;   
}