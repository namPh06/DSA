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
node *add (node *root , int u , int v , char c){
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
        else {
            if (root -> left != NULL) add (root -> left , u , v ,c);
            if (root -> right != NULL) add (root -> right , u , v ,c);
        }
    }
    return root;
}
set <int > se;
void solve (node *root , int cnt){
    if (!root -> left && !root -> right)
    se.insert (cnt);
    else {
        if (root -> left)
        solve (root -> left ,cnt+1);
        if (root -> right)
        solve (root -> right, cnt + 1);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        se.clear();
        int n;
        cin >> n;
        node *root = NULL;
        for (int i = 0;  i < n ; i++){
            int x ,y;
            char c;
            cin >> x >> y >> c;
            root = add (root, x , y,c);
        }
        solve (root , 0);
        if (se.size() > 1)
        cout << "0\n";
        else cout <<"1\n";
    }
    return 0;
}