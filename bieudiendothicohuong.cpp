#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int u , e;
        cin >> u >> e;
        vector <int > v[1001];
        for (int i = 0 ; i < e ; i++){
            int x , y;
            cin >> x >> y;
             v[x].push_back (y);
        }
        for (int i = 1; i <= u ; i++){
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