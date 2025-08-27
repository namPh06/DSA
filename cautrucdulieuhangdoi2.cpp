#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    queue <int> q;
    while (t--){
        string s;
        cin >> s;
        if (s == "PUSH"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if (s == "PRINTFRONT"){
            if (!q.empty()){
                cout << q.front()<< endl;
            }
            else cout <<"NONE\n";
        }
        else if ( s == "POP"){
            if (!q.empty())
            q.pop();
        }
    }
    return 0;
}