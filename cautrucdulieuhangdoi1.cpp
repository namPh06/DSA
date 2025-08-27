#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        queue<int> q;
        while (n--){
            int a;
            cin >> a;
            if (a == 1)
                cout << q.size() << endl;
            else if (a == 2){
                if (q.empty()) cout << "YES\n";
                else cout << "NO\n";
            }
            else if (a == 3){
                int b;
                cin >> b;
                q.push(b);
            }
            else if (a == 4){
                if (!q.empty())
                    q.pop();
            }
            else if (a == 5){
                if (!q.empty())
                    cout << q.front() << endl;
                else cout << "-1\n";
            }
            else if (a == 6){
                if (!q.empty())
                    cout << q.back() << endl;
                else cout << "-1\n";
            }
        }
    }
    return 0;
}