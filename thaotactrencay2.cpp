#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

node* insert(node* root, int val) {
    if (root == NULL)
        return new node(val);
    if (val < root->data){
        root->left = insert(root->left, val);
    }
    else if (val > root -> data){ 
        root->right = insert(root->right, val);
    }
    return root;
}

void preorder(node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

node* minNode(node* root) {
    node* tmp = root;
    while (tmp != NULL && tmp->left != NULL)
        tmp = tmp->left;
    return tmp;
}

node* deletenode(node* root, int key) {
    if (root == NULL) return root;
    
    if (key < root->data)
        root->left = deletenode(root->left, key);
    else if (key > root->data)
        root->right = deletenode(root->right, key);
    else {
        if (root->left == NULL) {
            node* tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == NULL) {
            node* tmp = root->left;
            delete root;
            return tmp;
        } else {
            node* tmp = minNode(root -> right);
            root->data = tmp->data;
            root->right = deletenode(root->right, tmp->data);
        }
    }
    return root;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    int cnt = 1;
    node *root = NULL;
    while (t--){
        string s;
        int x;
        cin >> s >> x;
        if (s == "ins"){
            root = insert (root, x);
        }
        else if (s == "del"){
            root = deletenode (root , x);
        }
        cout << "Query #" << cnt++ <<": ";
        preorder(root);
        cout << "\n";
    }
}   