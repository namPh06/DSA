#include <bits/stdc++.h>
using namespace std;
int const base = 1e9 + 7;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        priority_queue <int , vector <int >, greater <int>> pq;
        for (int i = 0; i < n ; i++){
            cin >> a[i];
            pq.push(a[i]);
        }
        long long ans = 0;
        while (pq.size() > 1){
            int b = pq.top();
            pq.pop();
            int c = pq.top();
            pq.pop();
            long long cost = (1LL * b + c) % base; 
            ans = (ans + cost) % base; 
            pq.push(cost);  
        }
        cout << ans << endl;
    }
    return 0;
}