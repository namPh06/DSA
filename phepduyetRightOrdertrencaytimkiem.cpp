#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
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
void rightLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->right) q.push(cur->right);
        if (cur->left) q.push(cur->left);
    }
    cout << endl;
}
void deleteTree(Node* root) {
    if (!root) return;
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
        rightLevelOrder(root);
        deleteTree(root);
    }
    return 0;
}
