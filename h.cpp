#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int a ,b;
        cin >> a >> b;
        long long tmp = abs (a - b);
        long long k = 0;
        while (true){
            long long sum = k*(k+1) / 2;
            if (sum >= tmp && (sum - tmp) % 2 == 0){
                cout << k <<"\n";
                break;
            }
            k++;
        }
    }
    return 0;
}	