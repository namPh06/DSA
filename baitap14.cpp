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
node *insert (node *root  , int val){
    if (root == NULL)
    return root = new node (val);
    if (val < root -> data)
    root -> left = insert (root -> left , val);
    else if (val > root -> data)
    root -> right = insert (root -> right ,val);
    return root;
}
void levelOrder(node *root){
    queue < node*> q;
    q.push(root);
    cout << root -> data <<" ";
    while (!q.empty()){
        node *root = q.front(); 
        q.pop();
        if (root -> right != NULL){
            q.push(root -> right);
            cout << root -> right -> data <<" ";
        }
        if (root -> left != NULL){
            q.push(root -> left);
            cout << root -> left -> data <<" ";
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        node *root = NULL;
        for (int i = 0; i < n ; i++){
            cin >> a[i];
            root = insert (root , a[i]);
        }
        levelOrder (root);
        cout << "\n";
    }
    return 0;
}