#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	vector <int> v1,v2;
	for (int i = 1 ; i <= n ; i++){
		if (i % 2== 0)
		v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	sort (v2.begin(),v2.end());
	sort (v1.begin() , v1.end(),cmp);
	int index1 = 0 , index2 = 0;
	for (int i = 1; i <= n ; i++){
		if (i % 2 != 0){
        cout << v2[index1] <<" ";
        index1++;
    }
        else {
        	cout << v1[index2] <<" ";
        	index2++;
		}
}
    return 0;
}