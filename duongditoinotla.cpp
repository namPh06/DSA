#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node (int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
int nt (int n){
    if ( n < 2)
    return 0;
    for (int i = 2; i <= sqrt(n) ; i++){
        if (n % i == 0)
        return 0;
    }
    return 1;
}
node *build(node *root, int u , int v , char c){
    if (root ==  NULL){
        root = new node (u);
        node *p = new node (v);
        if (c =='L')
        root -> left = p;
        else if (c == 'R')
        root -> right = p;
    }
    else {
        if (root -> data == u){
            node *p = new node (v);
            if (c == 'L')
            root -> left = p;
            else if (c == 'R')
            root -> right =  p;
        }
        else {
            if (root -> left != NULL){
                root -> left = build (root -> left , u , v , c);
            }
            if ( root -> right != NULL){
                root -> right = build (root -> right , u , v, c);
            }
        }
    }
    return root;
}
int res = 0;
void dfs (node *root, int cnt){
    if ( root == NULL)
    return;
    if (nt (root -> data)) cnt++;
    if (!root -> left && !root -> right){
        res = max (res , cnt);
    }
    dfs (root -> left , cnt);
    dfs (root -> right , cnt);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        res = 0;
        node *root = NULL;
        for (int i = 0; i < n ; i++){
            int u , v ;
            char c;
            cin >> u >> v >> c;
            root = build (root , u , v ,c);
        }
        dfs (root , 0);
        cout << res;
        cout <<"\n";
    }
}