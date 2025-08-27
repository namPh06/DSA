#include <bits/stdc++.h>
using namespace std;
long long solve (int n){
    queue < long long > q;
    q.push (4);
    q.push(7);
    while (!q.empty()){
        long long x = q.front(); 
        q.pop();
        if (x >= n){
            return x;
            break;        
        }
        q.push(x*10 + 4);
        q.push(x*10 + 7);
    }
    return 0;
}
int main(){
    int a, b;
    cin >> a >> b;
    long long sum = 0;
    for (int i = a; i <= b ; i++){
        sum += solve(i);
    }
    cout << sum;
    return 0;
}