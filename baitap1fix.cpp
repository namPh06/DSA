#include <bits/stdc++.h>
using namespace std;
void solve(int a[],int n,int k){
    int cnt = 0;
    while (1){
        if (cnt % k == 0){
            for (int i = 0; i< k ; i++)
            cout << a[i] <<" ";
            cout << endl;
        }
        int i = k -1 ;
        while (a[i] == n - k + i + 1 && i >= 0)
        i--;
        if ( i < 0)
        return;
        a[i]++;
        for (int j = i + 1;j < k ; j++)
        a[j] = a[j-1] + 1;
        cnt++;
    }
}
int main(){
    int n,k;
    cin >> n >> k;
   int a[n];
   for (int i = 0 ; i < k ; i++){
    a[i] = i + 1;
   }
   solve(a,n,k);
   return 0;
}