#include <bits/stdc++.h>
using namespace std;
void solve(int a[],int n){
    for (int i = 0 ; i < n ; i++){
        a[i] = 0;
    }
    while (1){
        for (int i = 0; i < n ; i++){
            cout << a[i];
        }
        for (int i = n - 1; i>= 0 ;i--){
            cout << a[i];
        }
        cout << " ";
        int i = n - 1;
        while (a[i]== 1 && i >= 0)
        i--;
        if (i < 0)
        return;
        a[i] = 1;
        for (int j = i + 1; j< n; j++)
        a[j] = 0; 
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 1; i <= n / 2 ; i++){
            solve(a,i);
        }
        cout << endl;
    }
    return 0;
}