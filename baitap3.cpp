#include <bits/stdc++.h>
using namespace std;
int n,a[20],used[20];
bool check(){
    int sum = 0;
    for (int i = 2 ; i <= n ; i++){
        sum += (a[i-1] - a[i]);
    }
    if (sum < 0)
    return false;
    return true;
}
void inkq(){
	if (check()){
	for (int i = 1; i <= n ;i++){
		cout << a[i] <<" ";
	}
	cout << endl;
  }
}
void backtrack (int pos){
	for (int i=1;i<=n;i++){
		if (used[i]== 0){
			a[pos] = i;
			used[i] = 1;
			if (pos == n){
				inkq();
			}
			else backtrack(pos +1);
			used[i] = 0;
		}
	}
}
int main(){
	memset(used,0,sizeof (used));
	cin >> n ;
	backtrack(1);
	cout << endl;
	return 0;
}