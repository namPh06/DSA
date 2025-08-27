#include <bits/stdc++.h>
using namespace std;
int a[20] , n , used[20];
bool check(){
    for (int i = 1; i< n ; i++){
        if (abs(a[i+1] - a[i])== 1)
        return false;
    }
    return true;
}   
void inkq(){
   if (check()){
    for (int i = 1; i<= n ; i++){
        cout << a[i];
    }
     cout << endl;
   }
}
void backtrack(int pos){
    for (int i = 1; i<=n ;i++){
        if (used[i] == 0){
            a[pos ] = i;
            used[i] = 1;
            if (pos == n)
            inkq();
            else backtrack(pos +  1);
            used[i] = 0;
        }
    }   
}
int main(){
    int t;
    cin >>t ;
    while (t--){
        cin >> n;
        backtrack(1);
        cout << endl;
    }
    return 0;
}