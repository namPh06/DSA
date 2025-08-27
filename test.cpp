#include <bits/stdc++.h>
using namespace std;
int max_n = 100000;
int prime[1000001];
void sang(){
    for (int i = 0 ; i <= max_n ; i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(max_n) ;i++){
        if (prime[i]){
            for (int j = i*i ; j <= max_n ; j+= i){
                prime[j] = 0;
            }
        }
    }   
}
int main(){
	sang();
	string s;
	while (cin >> s && s!= "0"){
		int res = -1;
		int len = s.size();
		for (int i  = 0 ; i < len; i++){
		int n = 0 ;
		for (int l = 1; l <= 5 && i + l  <= len ; l++){
			n = n* 10 + (s[i + l - 1] - '0');
			if (n < max_n && prime[n]){
				res = max(res, n);
			}
		}
	}
	cout << res <<"\n";
}
return 0;
}