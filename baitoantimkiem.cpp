#include <bits/stdc++.h>
using namespace std;
int find(int n,int s ,int k ,int a[]){
	long long sum = 0 ;
	int t = s;
	for (int i = s; i>= 0 ; i--){
		sum += a[i];
		if (sum <= k) 
		  t = i;
		  else break;
	}
	if (sum <= k)
	{
	return t;}
	else if (t == s && a[s] > k)
	{
	return -1; 
   }
   return t;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n,s,k;
		cin >> n >> s >> k;
		int a[n];
		for (int i = 0 ; i < n ; i++){
			cin >> a[i];
		}
		cout << find(n,s,k,a) << endl;
	}
	return 0;
}