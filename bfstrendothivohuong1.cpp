#include <bits/stdc++.h>
using namespace std;
vector <int > v[1001] ;
int used[1001] , tmp[1001];
int n , m , s ,t ;
void nhap(){
    cin >> n >> m >> s >> t;
    for (int i = 1; i<= n ; i++){
        v[i].clear();
        used[i] = 0;
    }
    for (int i = 0; i < m ; i++){
        int x  , y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i<= n ; i++){
        sort (v[i].begin() , v[i].end());
    }
}
void bfs(int u){
    queue <int > q;
    q.push(u);
    used[u] = 1;
    while (!q.empty()){
       int x = q.front();
       q.pop();
       for (int i : v[x]){
       	if (!used[i]){
        used[i] = 1;
        q.push(i);
        tmp[i] = x;
         }
       }
    }
}
void bfsPath(int s , int t){
     bfs(s);
     if (!used[t]){
        cout <<"-1\n";
        return;
     }
     vector < int > ans;
     while (s != t){
         ans.push_back(t);
         t = tmp[t];
     }
     ans.push_back(s);
//      for (int i = ans.size() - 1 ; i >= 0 ; i--){
//         cout << ans[i]<<" ";
//      }
//      cout << endl;
     cout << ans.size() - 1 << "\n";
}
int main(){
    int tc;
    cin >> tc;
    while (tc--){
        nhap();
        bfsPath(s,t);
    }
    cout << endl;
}