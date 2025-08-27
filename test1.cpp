#include <bits/stdc++.h>
using namespace std;
int n, k, t=0, r=0;
int a[1001];
int b[1001];
vector<vector<int>> g;

int main(){
	cin>>n>>k;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	quaylui(1,1,k);
	for(int i =g.size()-1;i>=0;i--){
		for(int j=0;j<g[i].size();j++)cout<<g[i][j]<<" ";
		cout<<endl;
	}
	cout<<t;
}