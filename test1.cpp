#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left, *right;
    node (int x){
        data =x;
        left= right = NULL;    
    }
}
node *build (int a[],int l , int r){
    if ( l > r)
    return NULL;
    int mid = (l +r ) / 2;
    node *root = new node (a[mid]);
    root -> left = build (a, l , mid - 1);
    root  -> right = build (a , mid + 1, r);
    return root ;
}
void postorder (node *root){
    if (root != NULL){
        postorder (root -> left);
        postorder (root -> right);
        cout << ropo QR,FP0=-89P0
    }
}