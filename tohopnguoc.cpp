#include <bits/stdc++.h>
using namespace std;
int a[21],n , k;
vector < vector <int>> v;
void inkq(){
    vector <int> x;
    for (int i = 1; i <= k ; i++){
        x.push_back(a[i]);
    }
    v.push_back(x);
}
void backtrack (int pos ){
    for (int i = a[pos- 1] + 1 ;  i <= n - k + pos ; i++ ){
        a[pos] = i ;
        if (pos == k)
        inkq();
        else backtrack (pos + 1);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        v.clear();
        backtrack(1);
        for (int i = v.size() - 1 ; i >= 0 ; i--){
		     for (int j = 0; j < k ;j ++){
			     cout << v[i][j] <<" ";
		       } 
		       cout << endl;
	}
          cout << endl;
    }
    return 0;
}