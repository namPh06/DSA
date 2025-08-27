#include <bits/stdc++.h>
using namespace std;
void solve(int a[],int n,int s){
    vector <int > v;
    for (int i = 1 ;i <= s; i++){
        if (s % i ==0){
            int sum = 0;
            for (int j = 0 ; j< n ; j++){
                sum += a[j];
                if (sum == i)
                sum = 0;
                else if (sum > i)
                break;
            }
            if (sum == 0){
                cout << i << endl;
                break;
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
          int s = 0;
          for (int i = 0 ; i <n ;i++){
            cin >> a[i];
            s += a[i];
          }
          solve(a,n,s);
    }
    return 0;
}