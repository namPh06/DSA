#include <bits/stdc++.h>
using namespace std;
int a[21], n , k , s;
int cnt = 0;
void inkq(){
    int sum = 0;
    for (int i = 1 ; i<= k ;i++){
        sum += a[i];
    }
    if (sum == s){
        cnt++;
    }
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
        while (true){
        cin >> n >> k >> s; 
        if (n == 0 && k == 0 && s == 0)
        break;
        backtrack(1);
        cout << cnt;
        cnt = 0;
        cout << endl;
        }
    return 0;
}