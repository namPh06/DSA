#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int k;
        cin >> k;
        string s;
        cin >> s;
        priority_queue <int > pq;
        map <char,int> mp;
        for (char x : s){
            mp[x]++;
        }
        for (char x : s){
            if (mp[x] > 0){
                pq.push(mp[x]);
            }
            mp[x] = 0;
        }
        while (k-- && !pq.empty()){
        	int u = pq.top();
        	pq.pop();
        	if ( u > 1) 
        	pq.push(u - 1);
		}
		long long res = 0;
		while (!pq.empty()){
		     int u = pq.top() ;
		     pq.pop();
		     res += 1ll* u * u;
		}
		cout << res << "\n";
    }
    return 0;
}