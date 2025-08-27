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
            node *p = new node(v);
            if (c == 'L')
            root -> left = p;
            else root -> right = p;
        }
        else {
            if (root -> left != NULL)
            root -> left = add (root -> left, u , v, c);
            if (root -> right != NULL)
            root -> right = add (root -> right , u , v ,c);
        }
    }
    return root;
}
int res = 1;
set < int > se;
void solve (node *root , int cnt){
    if (root -> left && ! root -> right || root -> right && !root -> left){
         res = 0;
    }   
    else if (!root -> left && !root -> right){
        se.insert(cnt);
    }
    else {
       solve (root -> left, cnt + 1);
       solve (root -> right , cnt + 1);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        node *root = NULL;
        for (int i = 0 ;i < n; i++){
            int x,y;
            char c;
            cin >> x >> y >> c;
           root = add (root , x , y, c);
        }
        res  = 1;
        solve (root , 0);
        cout <<res << "\n";
    }
    return 0;
}