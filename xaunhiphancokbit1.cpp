#include <bits/stdc++.h>
using namespace std;
int a[20],n,k;
bool check (){
	int sum = 0; 
	for (int i = 1; i <= n;i++){
		sum += a[i];
	}
	if (sum == k)
	return true;
	return false;
}
void inkq(){
	if (check()){
		for (int i = 1; i<= n;i++){
			cout << a[i];
		}
     cout << endl;
	}
}
void backtrack(int pos){
	for (int i = 0 ; i<= 1;i++){
		a[pos] = i;
		if (pos == n){
			inkq();
		}
		else backtrack(pos+1);
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> k;
		backtrack(1);
		cout << endl;
	}
	return 0;
}