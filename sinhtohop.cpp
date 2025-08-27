#include <bits/stdc++.h>
using namespace std;
int a[20], n , k;
int cnt = 0;
void inkq(){
    for (int i = 1 ; i<= k ;i++){
        cout << a[i];
    }
    cnt++;
    cout <<" ";
}
void backtrack (int pos){
    for (int i = a[pos - 1] + 1 ; i <= n - k + pos ; i++ ){
      a[pos] = i;
      if (pos == k)
      inkq();
      else backtrack (pos+1);  
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        backtrack(1);
        cout << cnt;
        cout << endl;
    }
    return 0;
}