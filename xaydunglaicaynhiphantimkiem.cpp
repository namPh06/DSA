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
    else if (val > root -> data){
        root -> right = insert (root -> right , val);
    }
    return root;
}
void preorder (node *root){
    if (root != NULL){
     cout << root -> data <<" ";
     preorder (root -> left );
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
        node *x = NULL;
        for (int i = 0; i < n ; i++){
            cin >> a[i];
            x = insert(x , a[i]);
        }
        preorder (x);
        cout << endl;
    }
    return 0;
}