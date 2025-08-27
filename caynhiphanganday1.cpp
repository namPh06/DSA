#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node (int x){
        data = x;
        left = right = NULL;
    }
};
node *build (vector <int > &a , int n , int i){
    if (i >= n)
    return NULL;
    node *root = new node (a[i]);
    root -> left = build (a, n , 2 * i + 1);
    root -> right = build (a , n , 2* i + 2);
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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector < int > v(n);
        for (int i = 0; i < n ; i++){
            cin >> v[i];
        }
        node *root = NULL;
        root = build (v, n , 0);
        inorder (root);
        cout <<"\n";
    }
    return 0;
}