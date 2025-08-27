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
node *add(node *root , int u , int v , char c){
    if (root == NULL){
        root = new node (u);
        node *p = new node (v);
        if (c == 'L')
        root -> left = p;
        else root -> right = p;
    }
    else {
        if (root -> data == u){
            node *p = new node (v);
            if ( c == 'L')
            root -> left = p;
            else root -> right = p;
        }
        else {
            if (root -> left != NULL)
            add (root -> left , u , v ,c);
            if (root -> right != NULL)
            add (root -> right ,u , v, c);
        }
    }
    return root;
}
void levelOrder(node *root){
    queue < node*> q;
    q.push(root);
    cout << root -> data <<" ";
    while (!q.empty()){
        node *root = q.front(); 
        q.pop();
        if (root -> left != NULL){
            q.push(root -> left);
            cout << root -> left -> data <<" ";
        }
        if (root -> right != NULL){
            q.push(root -> right);
            cout << root -> right -> data <<" ";
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        node *root = NULL;
        for (int i = 0 ; i < n ; i++){
            int x,y;
            char z;
            cin >> x >> y >> z;
            root  = add (root,x , y , z);
        }
        levelOrder (root);
        cout << endl;
    }
    return 0;
}