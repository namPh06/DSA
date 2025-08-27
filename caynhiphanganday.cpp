#include <bits/stdc++.h>
using namespace std;
int n , a[10005];
void inorder (int i){
    if (i >= n )   
    return;
    inorder (2*i+1);
    cout << a[i] <<" ";
    inorder (2*i+2);
}
int main(){
     ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0 ; i < n ; i++ )
        cin >> a[i];
        inorder(0);
        cout << "\n";
    }
    return 0;
}