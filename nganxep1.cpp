#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    stack <int > st;
    while (getline(cin,s)){
        stringstream ss(s);
        string token;
        ss >> token;
        if (token == "push"){
            int num;
            ss >> num;
            st.push(num);
        }
        else if (token == "pop"){
            if (!st.empty()){
                st.pop();
            }
        }
        else if (token == "show"){
            if (st.empty()){
               cout << "empty\n";
            }
            else {
                vector <int > v;
                while (!st.empty()){
                    v.push_back(st.top());
                    st.pop();
                }
                for (int i = v.size() - 1 ; i >= 0 ; i--){
                    cout << v[i]<<" ";
                    st.push(v[i]);
                }
                cout << endl;
            }
        }
    }
    return 0;
}