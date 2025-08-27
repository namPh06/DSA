#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    deque<int > q;

    while (t--){
        string s;
        cin >> s;
        if (s == "PUSHBACK"){
            int x;
            cin >> x;
            q.push_back(x);
        }
        else if (s == "PUSHFRONT"){
            int b;
            cin >> b;
            q.push_front(b);
        }
        else if (s == "PRINTFRONT"){
            if (!q.empty())
            cout << q.front() << endl;
            else cout <<"NONE\n";
        }
        else if (s == "PRINTBACK"){
            if (!q.empty()){
                cout << q.back() << endl;
            }
            else cout <<"NONE\n";
        }
        else if (s == "POPFRONT"){
            if (!q.empty())
            q.pop_front();
        }
        else if (s == "POPBACK"){
            if (!q.empty())
            q.pop_back();
        }
    }
    return 0;
}