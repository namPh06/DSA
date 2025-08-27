#include <bits/stdc++.h>
using namespace std;
int root[100005], size[100005];
int find(int x){
    if (x == root[x])
    return x;
    return root[x] = find(root[x]);
}
void union(int x, int y){
    int rootx = find (x) , rooty = findroot(y);
    if (rootx != rooty){
        if (size[rootx] < size[rooty])
        swap(rootx,rootu)
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        c
    }
}