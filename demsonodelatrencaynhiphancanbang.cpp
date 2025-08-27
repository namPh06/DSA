#include <bits/stdc++.h>
using namespace std;
int d = 0;
bool check = true;
int res = 0;
long long sum = 0;
int ans = -1e9;
class Node {
public:
	int x;
	Node* left;
	Node* right;

	Node(int x) {
		this->x = x;
		left = nullptr;
		right = nullptr;
	}
};

void connect(Node* r, int u, int v, char c) {
	if (r == nullptr) return;
	if (r->x == u) {
		Node* n = new Node(v);
		if (c == 'L') r->left = n;
		else r->right = n;
	}
	else {
		connect(r->left, u, v, c);
		connect(r->right, u, v, c);
	}
}

void postOrder(Node* root) {
	if (root != nullptr) {
		if (root->left == nullptr && root->right == nullptr) {
			res++;
			return;
		}
		postOrder(root->left);
		postOrder(root->right);
	}
}

Node* buildTree(int arr[], int left, int right) {
	if (left <= right) {
		int mid = (left + right) / 2;
		Node* n = new Node(arr[mid]);

		n->left = buildTree(arr, left, mid - 1);
		n->right = buildTree(arr, mid + 1, right);

		return n;
	}
	else return nullptr;
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int arr[1001];

		Node* root = nullptr;


		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		sort(arr + 1, arr + n + 1);

		root = buildTree(arr, 1, n);

		res = 0;

		postOrder(root);
		cout << res;
		cout << endl;
	}
	return 0;
}