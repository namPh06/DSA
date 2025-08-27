#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    cin.ignore();
    stack<int> st;
    while (t--){
        string s;
        getline (cin,s);
        stringstream ss(s);
        string token;
        ss >> token;
        if (token == "PUSH"){
            int num;
            ss >> num;
            st.push(num);
        }
        else if (token == "POP"){
            if (!st.empty()){
                st.pop();
            }
        }
        else if (token == "PRINT"){
            if (st.empty()){
               cout << "NONE\n";
            }
            else {
                cout << st.top() << endl; 
            }
        }
    }
    return 0;
}