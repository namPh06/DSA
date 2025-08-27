#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	vector < int > v1,v2;
	for (int i = 0 ; i< n ; i++){
		cin >> a[i];
		if (a[i] < 0)
		v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	long long res1,res2;
	sort (v1.begin() , v1.end());
	sort (v2.begin() , v2.end());
    if (v1.size() >= 2){
    	 res1 = v1[0] * v1[1];
	}
	if (v2.size() >= 3){
	res2 = v2[v2.size()-1] * v2[v2.size()- 2] * v2[v2.size()-3]; 
	}
	else  res2 = v2[v2.size() - 1] * v2[v2.size()- 2];
	cout << max(res1,res2);
	return 0;
}