#include <bits/stdc++.h>
using namespace std;
int qhd(int a[] ,int n){
    int tang[n] , giam[n] , ans;
    tang[0] = 1; giam[n-1] = 1;
    for (int i = 1; i<n ; i++){
        if (a[i] > a[i-1])
        tang[i] = tang[i-1] + 1;
        else tang[i] = 1;
    }
    for (int i = n - 2 ; i >= 0 ; i--){
        if (a[i] >  a[i+1])
        giam[i] = giam[i+1] +  1;
        else giam[i] = 1;
    }
    ans = tang[0] + giam[0] - 1;
    for (int i =  1; i< n ; i++){
        ans = max(ans , tang[i] + giam[i] - 1);
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[100001];
        for (int i = 0 ; i< n ; i++){
            cin >> a[i];
        }
        cout << qhd(a,n)<< endl;
    }
    return 0;
}