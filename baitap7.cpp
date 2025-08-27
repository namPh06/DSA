#include <bits/stdc++.h>
using namespace std;
double solve(int a,int b ,int c){
    double left = 0.0, right = 1000.0;
    for (int i = 0 ; i< 100; i++){
        double mid = (left + right) / 2.0;
        double tmp = a*mid * mid * mid + b*mid;
        if ( tmp < c)
        left = mid;
        else right = mid;
    }
    return (left + right) / 2.0;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int a,b,c;
        cin >> a >> b >> c;
        cout << fixed << setprecision(4)<<  solve(a,b,c) << endl;
    }
    return 0;
}