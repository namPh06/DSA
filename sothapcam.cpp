#include <bits/stdc++.h>
using namespace std;
vector <int > v;
void sang(){
    queue < pair < long long,long long >> pq;
    for (int i = 1 ; i <= 9 ; i++){
        pq.push({i,i});
    }
    while (true){
        pair <long long ,long long > x = pq.front();
        pq.pop();
        long long a = x.first , b = x.second;
        if (b == 10){
            v.push_back(a);
            if (v.size() == 2e5)
            return;
        }
        for (int i = 0 ;i <= 9 ; i++){
            if (b + i <= 10){
                pq.push({a*10 + i , b + i});
            }
            else break;
        }
    }
}
signed main(){
    sang();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << v[n- 1] << endl;
    }
    return 0;
}