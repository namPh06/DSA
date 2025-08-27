#include <bits/stdc++.h>
using namespace std;
int a[101] , b[101],c[101] ;
int n , k ,cnt;
vector < vector <int>> v;
void inkq(int pos){
    vector <int > v1;
    for (int i = 1; i <=  pos;i++){
         v1.push_back(b[i]);
    }
    v.push_back(v1);
}
void backtrack(int start, int i , int s){
    for (int j = start ; j <= n ; j++ ){
         b[i] = c[j];
         if  (s - c[j] ==  0){
                inkq(i);
         } 
         else if (c[j] < s){
            backtrack ( j + 1 , i + 1 , s - c[j]);
         }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
    v.clear();
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort (a,a+n);
    for (int i = 0 ; i < n ;i++){
        c[i+1] = a[i];
    }
    backtrack(1,1, k);
    if (v.size() == 0){
        cout <<"-1" << endl;
    }
    else {
    for (int i = 0 ; i < v.size() ; i++){
        cout <<"[";
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
            if (j != v[i].size() - 1)
            cout <<" ";
        }
        cout <<"] ";
    }
    cout << endl;}
    }
    return 0;
}