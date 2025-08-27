#include <bits/stdc++.h>
using namespace std;
long long max_sum (string  a,string b){
	for (int i = 0; i < a.size(); i++){
		if (a[i] == '5' )
		a[i] = '6';
	}
	for (int i = 0; i < b.size(); i++){
		if (b[i] == '5' )
		b[i] = '6';
	}
	return stoi(a) + stoi (b);
}
long long min_sum (string  a,string b){
	for (int i = 0; i < a.size(); i++){
		if (a[i] == '6' )
		a[i] = '5';
	}
	for (int i = 0; i < b.size(); i++){
		if (b[i] == '6' )
		b[i] = '5';
	}
	return stoi(a) + stoi (b);
}
int main(){
		string a,b;
		cin >> a >> b;
		cout << min_sum (a,b) <<" "<< max_sum(a,b);
	return 0; 		
}