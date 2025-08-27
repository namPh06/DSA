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
node *add (node *root , int u , int v, char c){
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
            if (c == 'L')
            root -> left = p;
            else root -> right = p;
        }
        else{
            if (root-> left != NULL)
            add (root-> left , u , v, c);
            if (root -> right != NULL)
            add (root -> right , u , v ,c);
        }
    }
    return root;
}
void duyetxoanoc(node *root){
    stack <node*> st1, st2;
    st1.push(root);
    while (!st1.empty() || !st2.empty()){
        while (!st1.empty()){
            node *p = st1.top();
            st1.pop();
            cout << p -> data <<" ";
            if (p -> right != NULL)
            st2.push(p -> right);
            if (p -> left != NULL)
            st2.push(p -> left);
        }
        while (!st2.empty()){
            node *p = st2.top();
            st2.pop();
            cout << p -> data <<" ";
            if (p -> left != NULL)
            st1.push(p-> left);
            if (p -> right != NULL)
            st1.push(p -> right);
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
        for(int i = 0; i < n ; i++){
            int x, y;
            char c;
            cin >> x >> y >> c;
            root = add (root, x, y,c);
        }
        duyetxoanoc(root);
        cout << endl;
    }
    return 0;
}