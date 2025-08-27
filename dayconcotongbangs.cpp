#include <iostream>
#include <algorithm>

using namespace std;

int n, s, Min = 1e9, dem = 0; 

void Try(int a[], int i, int sum) {
    if (sum == 0) { 
        Min = min(Min, dem); 
        return;
    }
    if (i > n || sum < 0) return; 

    
    if (sum >= a[i]) {
        dem++;
        Try(a, i + 1, sum - a[i]);
        dem--; 
    }

    
    Try(a, i + 1, sum);
}

int main() {
    cin >> n >> s;
    int a[100];
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

   
    sort(a + 1, a + n + 1, greater<int>());

    Try(a, 1, s);

    
    if (Min == 1e9) cout << "-1";
    else cout << Min;

    return 0;
}