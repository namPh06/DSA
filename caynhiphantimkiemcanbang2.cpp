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
node *build(int a[] , int l , int r){
    if ( l > r)
    return NULL;
    int mid = (l+r) / 2;
    node *root = new node (a[mid]);
    root -> left = build (a, l , mid - 1);
    root -> right = build (a , mid + 1, r);
    return root;
}
void preorder (node *root){
    if (root != NULL){
        cout << root -> data <<" ";
        preorder (root -> left);
        preorder (root -> right);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        sort ( a, a + n);
        node *root = build (a, 0 , n - 1);
        preorder (root);
        cout << endl;
    }
    return 0;
}