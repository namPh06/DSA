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
    }AS
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
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
    string s;
    node* root = NULL;
    while (getline(cin, s)) {
        if (s.empty())
        continue;
        stringstream ss(s);
        int token;
        ss >> token;
        if (token == 1) {
            int num;
            ss >> num;
            root = insert(root, num);
        } else if (token == 2) {
            int num;
            ss >> num;
            root = deletenode(root, num);
        } else if (token == 3) {
            preorder(root);
            cout << endl;
        } else if (token == 4) {
            inorder(root);
            cout << endl;
        } else if (token == 5) {
            postorder(root);
            cout << endl;
        }
    }
}   