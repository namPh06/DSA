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
        node *x = NULL;
        for (int i = 0;  i < n ; i++){
            cin >> a[i];
            x = insert (x, a[i]);
        }
        postorder (x);
        cout << endl;
    }
    return 0;
}