#include <bits/stdc++.h>
using namespace std;
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
            ans += b + c;
            pq.push(b + c);
        }
        cout << ans << endl;
    }
    return 0;
}