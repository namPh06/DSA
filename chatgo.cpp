#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        long long a[n];
        priority_queue <int , vector <int >, greater <int>> pq; 
        for (int i = 0; i < n ; i++){
            cin >>a[i];
            pq.push(a[i]);
        }
        long long sum = 0;
        while (pq.size() > 1){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            sum += x + y;
            pq.push(x + y);
        }
        cout << sum <<"\n";
    }
    return 0;
}