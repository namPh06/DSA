#include <bits/stdc++.h>
using namespace std;
int n,x;
bool cmp(int a,int b) {
	if (abs(x-a) >= abs(x-b))
    return 0;
    return 1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		long long  a[n];
		for (int i = 0 ; i<n; i++) {
			cin >> a[i];
		}
		stable_sort (a, a +n, cmp);
		for (int i = 0 ; i < n; i++) {
			cout << a[i] <<" ";
		}
		cout << endl;
	}
	return 0;
}