#include <bits/stdc++.h>
using namespace std;
void interchange_sort(int a[], int n){
	vector<vector <int> > N;
	for (int i = 0 ; i < n - 1; i++){
		for (int j = i + 1 ; j < n; j++){
			if (a[i] > a[j])
			swap(a[i],a[j]);
		}
	   vector <int > V;
	   for (int i = 0 ; i < n ;i++) V.push_back(a[i]);
	   N.push_back(V);
	}
	for (int i = N.size() - 1 ; i >= 0 ; i--){
		cout << "Buoc "<< i+1 <<": ";
		for (int j = 0 ; j < n ; j++){
			cout << N[i][j] <<" ";
		}
		cout << endl;
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	interchange_sort(a,n);
	cout << endl;
}
	return 0;
}