#include <bits/stdc++.h>
using namespace std;
int v[1001][1001];
int n, m;
int check(){
    for (int i = 1; i <= n ; i++){
        int cnt1 = 0 ,  cnt2 = 0;
        for (int j = 1; j<= n ; j++){
            if (v[i][j]) cnt1++;
            if (v[j][i]) cnt2++;
        }
        if (cnt1 != cnt2)
        return 0;
    }
    return 1;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        memset (v, 0 , sizeof (v)); 
        for (int i = 0 ; i < m ; i++){
        int x,y;
        cin >> x >> y;
        v[x][y] = 1;
    }
    cout << check() << endl;
    }
    return 0;
}