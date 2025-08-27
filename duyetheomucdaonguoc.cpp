#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
void reverseLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    stack<int> st;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        st.push(curr->val);
        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        map<int, Node*> nodes;
        map<int, bool> isChild;
        for (int i = 0; i < N; ++i) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (!nodes[u]) nodes[u] = new Node(u);
            if (!nodes[v]) nodes[v] = new Node(v);
            if (c == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
            isChild[v] = true;
        }
        Node* root = nullptr;
        for (auto& pair : nodes) {
            if (!isChild[pair.first]) {
                root = pair.second;
                break;
            }
        }
        reverseLevelOrder(root);
    }
    return 0;
}
