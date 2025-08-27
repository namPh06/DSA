#include <bits/stdc++.h>
using namespace std;
int n, p, s;
int b[1005];
vector <int> v;
vector<vector<int>> results;
int cnt = 0;

int nt(int n){
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

void ghep(){
    for(int i = p + 1; i <= s; i++){
        if (nt(i))
            v.push_back(i);
    }
}

void inkq(){
    vector<int> temp;
    for (int i = 1; i <= n; i++){
        temp.push_back(b[i]);
    }
    results.push_back(temp);
}

void backtrack(int i, int sum, int pos){
    for (int j = pos; j < v.size(); j++){
        if (sum + v[j] <= s){
            b[i] = v[j];
            sum += v[j];
            if (sum == s && i == n){
                cnt++;
                inkq();
            }
            else if (i < n) backtrack(i+1, sum, j + 1);
            sum -= v[j];
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cnt = 0;
        results.clear();
        v.clear();
        cin >> n >> p >> s;
        ghep();
        backtrack(1, 0, 0);
        cout << cnt << endl;
        sort(results.begin(), results.end());
        for(auto res : results){
            for(int x : res){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}