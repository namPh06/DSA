#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int a[],int n){
	vector < vector <int >> v;
	bool check;
	for (int i = 0 ; i < n- 1;i++){
		check = false;
		for (int j = 0 ; j < n - i - 1; j++){
			if (a[j] > a[j+1]){
			swap(a[j],a[j+1]);
			check = true;
		}
		}
		if (!check)
		break;
		vector <int > x;
		for (int i = 0 ; i < n;i++){
			x.push_back(a[i]);
		}
		v.push_back(x);
	}
	for (int i = v.size()- 1; i >= 0 ;i--){
		cout <<"Buoc "<< i+1 <<": ";
		for (int j = 0 ; j < n ;j++){
			cout << v[i][j] <<" ";
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
		for (int i = 0 ; i <  n; i++){
			cin >> a[i];
		}
		bubble_sort(a,n);
		cout << endl;
	}
	return 0;
}