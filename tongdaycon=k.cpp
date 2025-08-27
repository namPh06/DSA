#include <bits/stdc++.h>
using namespace std;
int a[101] , b[101] ;
int n , k ,cnt;
vector < vector <int>> v;
void inkq(int pos){
    vector <int > v1;
    for (int i = 1; i<= pos;i++){
         v1.push_back(b[i]);
    }
    v.push_back(v1);
}
void backtrack(int start, int i , int s){
    for (int j = start ; j <= n ; j++ ){
         b[i] = a[j];
         if  (s - a[j] ==  0){
                inkq(i);
                cnt++;
         } 
         else if (a[j] < s){
            backtrack ( j + 1, i + 1 , s - a[j]);
         }
    }
}
int main(){
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    backtrack(1,1, k);
    for (int i = v.size() - 1 ; i >= 0 ; i--){
        for (int j = 0 ; j < v[i].size() ; j++) {
            cout << v[i][j]<<" ";
        }
        cout << endl;
    }
    //  for(int i = 0 ; i <= v.size() ; i++){
    //     for (int j = 0 ; j < v[i].size() ; j++) {
    //         cout << v[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    cout << cnt;
    return 0;
}