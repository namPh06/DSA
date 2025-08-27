#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k ; 
        cin >>  n >> k;
        vector <int > a(k);
        for (int i =0 ; i < k ; i++){
            cin >> a[i];
        }
        vector <int > v = a;
        int i = k - 1;
        while (i >= 0 && v[i] == n - k + i + 1){
            i--;
        }
        if (i < 0){
            cout << k << endl;

        }
        else {
            v[i]++;
            for (int j =  i + 1 ; j < k ;j++){
                v[j] = v[j- 1]+1;
            }
        unordered_set <int > se;
        for (int i = 0 ; i< k ;i++){
            se.insert (a[i]);
        }
        int cnt = 0;
        for (int x : v){
            if (se.find(x) == se.end())
            cnt++;
        }
        cout << se.size() - cnt<< endl;
        }
    }
    return 0;
}