#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int u,e;
		cin >> u >> e;
		vector <int > v[1001];
		while ( e-- ){
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i =1; i <= u; i++){
			cout << i <<": ";
			for (int a : v[i]){
				cout << a <<" ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}