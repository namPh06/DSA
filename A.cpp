#include <bits/stdc++.h>
using namespace std;
long long x[301] , y[301];
bool check (int i , int j , int k){
    return (x[j] - x[i])*(y[k] - y[i]) == (x[k] - x[i])* (y[j] - y[i]); 
}
int main(){
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> x[i] >> y[i];
    }
    long long sum = 1ll * n *(n-1)*(n-2) / 6;
    long long cnt = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = i+1 ; j < n ; j++){
            for (int k = j + 1; k < n ; k++){
                if (check (i , j , k ))
                cnt++;
            }
        }
    }
    cout << sum - cnt;
    return 0;