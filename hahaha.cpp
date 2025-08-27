#include <bits/stdc++.h>
using namespace std;
int a[20], n;
char b[20];
void check(){
	for (int i = 1;i <= n;i++){
		if (a[i] == 1)
		b[i] = 'H';
		else b[i] ='A';
	}
}
bool check1(){
    for (int i = 1 ; i <= n -1; i++){
        if (b[i] == 'H' && b[i+1] == 'H' )
        return false; 
    } 
   return true;
}
bool check2(){
    if (b[1] != 'H' || b[n] !='A')
    return false;
    return true;
}
void inkq(){
    check();
    if (check1() && check2()){
        for (int i = 1; i<=n ; i++){
            cout << b[i]; 
        }
        cout << endl;
    }
}
void backtrack(int pos){
	for (int i = 0; i<= 1;i++){
		a[pos] = i;
		if (pos == n)
		inkq();
		else backtrack(pos+1);
	}
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        backtrack(1);
    }
    return 0;
}