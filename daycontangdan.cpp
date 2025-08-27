#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> b;
vector<string> v;
void chuyenhoa(int k){
	string s="";
	for(int i =0;i<=k;i++){
		s+=to_string(b[i])+" ";
	}
	v.push_back(s);
}
void in(){
	for(int i=0;i<v.size();i++)cout<<v[i]<<"\n";
}
void quaylui(int x,int l,int i){
	for(int j =x;j<=n;j++){
		if(a[j]>b[i-1]){
			b.push_back(a[j]);
			chuyenhoa(i);		
			quaylui(j+1,l,i+1);
			b.pop_back();
		}
	}

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i =1;i<=n;i++){
		int x; cin>>x;
		a.push_back(x);	
	}
	for(int i =0;i<n-1;i++){
		b.clear();
		b.push_back(a[i]);
		quaylui(i,i,1);
	}
	sort(v.begin(), v.end());
	in();
}