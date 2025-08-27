#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <long long > v(n+1,0);
        v[0] = 1;
        int k = 3;
        for (int i = 1; i <= n ;i++){
            for (int j = 1; j <= min(i,k); j++){
                v[i] = v[i] + v[i-j];
            }
        }   
        cout << v[n]<< endl;
    }
    return 0;
}