#include <bits/stdc++.h>
using namespace std;
int solve(int s , int t){
    queue < pair <int,int >> q;
    q.push({s,0});
    set <int > se;
    se.insert (s);
    while (!q.empty()){
        pair <int ,int > x = q.front();
        q.pop();
        if (x.first == t)
        return x.second;
        if (x.first - 1 > 0 && se.count (x.first - 1) == 0){
            q.push({x.first - 1, x.second + 1});
            se.insert (x.first -  1);
        }
        for (int i = 2; i <= sqrt(x.first) ; i++){
            if (x.first % i == 0){
                int res = max (i , x.first / i);
                if (se.count (res) == 0){
                    q.push({res, x.second + 1});
                    se.insert (res);
                }
            }
        }
    }
    return -1;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int s;
        cin >> s;
        cout << solve (s,1) << endl;
    }
    return 0;
}