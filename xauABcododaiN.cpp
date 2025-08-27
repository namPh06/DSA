#include <bits/stdc++.h>
using namespace std;
int a[15], n;
char b[15];
void check(){
	for (int i = 1 ; i <= n;i++){
		if (a[i] == 0)
		b[i] = 'A';
		else b[i] ='B';
	}
}
void inkq(){
	check();
	for (int i = 1 ; i<= n ;i++){
		cout << b[i];
	}
	cout << " ";
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
		cout << endl;
	}
	return 0;
}