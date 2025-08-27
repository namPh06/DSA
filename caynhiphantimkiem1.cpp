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
node *insert (node *root , int val){
    if (root == NULL){
        return new node (val);
    }
    if (val < root -> data){
        root -> left = insert (root -> left , val);
    }
    else {
        root -> right = insert (root -> right , val);
    }
    return root;
}
void postorder (node *root){
    if (root != NULL){
        postorder (root -> left);
        postorder (root -> right);
        cout << root -> data << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int cnt = 1;
    while (t--){
        cout << "Test #" << cnt++ <<": ";
        int n;
        cin >> n;
        int a[n];
        node *root = NULL;
        for (int i = 0; i < n ; i++){
            cin >> a[i];
            root = insert (root, a[i]);
        }
        postorder (root);
        cout <<"\n";
    }
    return 0;
}
