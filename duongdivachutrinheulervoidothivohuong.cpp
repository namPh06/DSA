#include <bits/stdc++.h>
using namespace std;
vector <int > v[1001];
bool check[1001];
int n , m;
void nhap(){
	cin >> n >> m;
	for (int i = 1; i<= n ; i++){
		v[i].clear();
	}
	for (int i = 0 ; i< m ; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}
void Euler(){
	int cnt = 0;
	for (int i = 1; i<= n ; i++){
		if (v[i].size() % 2 == 1)
		cnt++;
		
	}
	if (cnt == 2)
	cout << "1\n";
	else if (cnt == 0)
	cout << "2\n";
	 else cout << "0\n";
}
int main(){
	int t;
	cin >> t;
	while (t--){
		nhap();
		Euler();
	}
	return 0;
}