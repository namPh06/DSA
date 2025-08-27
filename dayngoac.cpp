#include <bits/stdc++.h>
using namespace std;
int a[101], n;
char b[101];
vector <string > v;
bool check(string s){
    stack < char > st;
    for (char x : s){
        if (x == '('){
            st.push(x);
        }
        else {
            if (st.empty())
            return 0;
            st.pop();
        }
    }
    return st.empty();  
}
void solve(){
	for (int i = 1 ; i <= 2*n;i++){
		if (a[i] == 0)
		b[i] = '(';
		else b[i] =')';
	}
}
void inkq(){
	solve();
    string s = "";
	for (int i = 1 ; i<= 2*n ;i++){
		s += b[i];
	}
	if (check(s)){
        v.push_back(s);
    }
}
void backtrack(int pos){
	for (int i = 0; i<= 1;i++){
		a[pos] = i;
		if (pos == 2*n)
		inkq();
		else backtrack(pos+1);
	}
}
int main(){
		cin >> n;
		backtrack(1);
        cout << v.size() << endl;
        for (string x : v){
            cout << x << endl;
        }
	return 0;
}