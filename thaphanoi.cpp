#include <bits/stdc++.h>
using namespace std;
void solve (int n,char a, char b ,char c ){
    if ( n == 1)
    cout << a <<" -> " << c << endl;
    else {
        solve(n-1,a,c,b);
        cout << a <<" -> "<< c << endl;
        solve(n-1,b,a,c);
    }
}
int main(){
    int n;
    cin >> n;
    solve(n,'A','B','C');
    return 0;
}