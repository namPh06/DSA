#include <bits/stdc++.h>
using namespace std;
char m[100];
char solve (long long k , int  x , int y){
    if (k % 4 == 0 || (k-2) % 2 == 0 )
    return m[x];
    else if ((k-1) % 4 == 0) return m[y];
    else {
        return solve (k/4, x + 2 , y + 2);
    }
}
int main(){
    int t;
    cin >> t;
    for (int i = 65 ; i <= 90 ; i++){
        m[i-64] = char (i);
    }
    while (t--){
        long long n , k;
        cin >> n >> k;
        cout << solve (k - 1 , 1, 2) <<"\n";
    }
    return 0;
}