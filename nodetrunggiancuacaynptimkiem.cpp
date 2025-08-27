#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
node *insert (node *root, int val){
    if (root == NULL){
        return new node (val);
    }
    if (val < root -> data){
        root -> left = insert (root -> left , val);
    }
    else if (val > root -> data){
        root -> right = insert (root -> right , val);
    }
    return root;
}
int cnt = 0;
void solve(node *t){
    if (!t -> left &&  !t-> right)
    cnt++;
    else{
        if (t -> left)
        solve(t -> left);
        if (t -> right)
        solve (t -> right);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cnt = 0;
        int n;
        cin >> n;
        int a[n];
        node *root = NULL;
        for (int i = 0; i < n ; i++){
            cin >> a[i];
            root = insert (root , a[i]);
        }
        solve (root);
        cout << n - cnt;
        cout << endl;
    }
    return 0;
}