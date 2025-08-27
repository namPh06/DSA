#include <bits/stdc++.h>
using namespace std;
int a[101],used[101],n;
bool check(){
    int sum = 0;
    for (int i = 1; i < n ; i++){
        sum +=  a[i] - a[i+1];
    }
    if (sum > 0)
    return true;
    return false;
}
void inkq(){
    if (check()){
        for (int i = 1 ; i <= n ; i++){
            cout << a[i] <<" ";
        }
        cout << endl;
    }
}
void backtrack(int pos){
    for (int i = 1; i<= n ; i++){
        if (used[i] == 0){
            a[pos] = i;
            used[i] = 1;
            if (pos == n)
            inkq();
            else backtrack(pos + 1);
            used[i] = 0;
        }
    }
}
int main(){
    cin >> n;
    backtrack(1);
    return 0;
}