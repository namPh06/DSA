#include <bits/stdc++.h>
using namespace std;
int a[100],n;
bool tn(){
	for (int i = 1;i <= n / 2;i++){
		if (a[i] != a[n - i + 1])
		return false;
	}
	return true;
}
void inkq(){
	if (tn()){
	for (int  i = 1 ;i<= n; i++){
		cout << a[i]<<" ";
	}
	cout << endl;
}
}
void backtrack (int pos){
	for (int i = 0 ; i<=1;i++){
		a[pos] = i;
		if (pos == n){
			inkq();
		}
		else backtrack(pos + 1);
	}
}
int main(){
	cin >> n;
	backtrack(1);
	return 0;
}