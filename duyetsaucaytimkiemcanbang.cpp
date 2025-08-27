#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node (int x ){
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
void postorder (node *root){
    if (root != NULL){
        postorder (root -> left);
        postorder (root -> right);
        cout << root -> data <<" ";
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
        sort (a, a + n);
        node *root = build ( a, 0 , n - 1);
        postorder (root);
        cout << endl;
    }
    return 0;
}