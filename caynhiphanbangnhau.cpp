#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string tmp1 = "" , tmp2 = "";
        for (int i = 0; i < n ; i++){
             string x, y, c;
            cin >> x >> y >> c;
            tmp1 += x ; tmp1 += y ; tmp1 += c;
        }
        int m;
        cin >> m;
        for (int i = 0 ; i<  m; i++){
            string e , f ,g;
            cin >> e >> f >> g;
            tmp2 += e ; tmp2 += f ; tmp2 += g;
        }
        if (tmp1 == tmp2)
        cout <<"1\n";
        else cout <<"0\n";
    }
    return 0;
}