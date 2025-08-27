#include <bits/stdc++.h>
using namespace std;
int n, a[20];
vector < vector <int >> v1;
void backtrack(int i , vector <int > &v , int sum  ){
    for (int j = i ; j < n ; j++){
        v.push_back(a[j]);
        sum += a[j];
        if ( sum % 2 != 0){
            v1.push_back(v);
        }
        backtrack( j + 1 , v, sum);
        sum -= a[j];
        v.pop_back();
    }
}
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        v1.clear();
        cin >> n;
        for (int i = 0;  i < n ; i++){
            cin >> a[i];
        }
        sort(a , a + n , cmp);
        vector < int > v;
        backtrack(0, v, 0);
        sort (v1.begin() , v1.end());
        for (auto v : v1){
            for (int x : v){
                cout << x <<" ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}