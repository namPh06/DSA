#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    queue <int > q;
    set < int > se;
    q.push(n);
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 1 ; i <= sqrt(x) ; i++){
            if (x % i == 0){
                int j = x / i;
                int res = (i - 1) * (j + 1);
                if (se.count(res) == 0){
                    se.insert (res);
                    q.push(res);
                }
            }
        }
    }
    cout << se.size() << endl;
    for (int c : se){
        cout << c <<" ";
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        solve(n);
        cout << endl;
    }
    return 0; 
}