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
node *build (int a[] , int n , int index){
    if (index >= n) 
    return NULL;
    node *root = new node (a[index]);
    root -> left = build (a, n , index*2 + 1);
    root -> right = build (a, n , index*2 + 2);
    return root;
}
void inorder (node *root){
    if (root != NULL){
        inorder (root -> left);
        cout << root -> data <<" ";
        inorder (root -> right);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0;  i < n ; i++){
            cin >> a[i];
        }
        node *root = build (a, n , 0);
        inorder (root);
        cout << "\n";
    }
    return 0;
}