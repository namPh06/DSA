#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long b){
     if (abs(0-a) >= abs(0-b))
     return 0;
     return 1;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		for (int i = 0 ; i< n;i++){
			cin >> a[i];
		}
		vector < long long > v;
		for(int i = 0 ; i < n;i++){
			for (int j = i+1;j< n;j++)
			v.push_back(a[i] + a[j]);
		}
        stable_sort(v.begin(), v.end(),cmp);
        cout << v[0] << endl;
	}
	return 0;
}