#include <bits/stdc++.h>
using namespace std;
int solve (int s , int t){
    queue < pair <int,int >> q;
    q.push({s,0});
    set <int > used;
    used.insert(s);
    while (!q.empty()){
        pair <int,int > x = q.front();
        q.pop();
        if (x.first == t)
        return x.second;
        if ( x.first % 2 == 0 && used.count(x.first / 2) == 0 ){
            q.push({x.first / 2 , x.second + 1});
            used.insert (x.first / 2);
        } 
        if ( x.first % 3 == 0 && used.count(x.first / 3) == 0 ){
            q.push({x.first / 3 , x.second + 1});
            used.insert (x.first / 3);
        }
        if ( x.first - 1 > 0 && used.count(x.first - 1) == 0 ){
            q.push({x.first - 1, x.second + 1});
            used.insert (x.first - 1);
        }
    }
    return 0;
}
int main(){ 
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << solve(n,1) << endl;
    }
    return 0;
}