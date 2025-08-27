#include <bits/stdc++.h>
using namespace std;
int  a[25], used[25] = {0}; 
vector <string > v;
string m;
bool check(){
    return v[a[n] - 1] == m;
}
void inkq(){
   if (check()){
    for 
   }
}
void backtrack(int pos){
    for (int i = 1; i <= n ; i++){
        if (used[i] == 0){
            a[pos] = i;
            used[i] = 1;
            if (pos == n){
                inkq();
            }
            else backtrack(pos + 1);
            used[i] = 0;x
        }
    }
}