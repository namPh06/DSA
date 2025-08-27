#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = right = nullptr;
    }
};
Node* insert(Node* root, int x) {
    if (root == nullptr) return new Node(x);
    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        Node* root = nullptr;
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        preorder(root);
        cout << endl;
        deleteTree(root); 
    }
    return 0;
}
