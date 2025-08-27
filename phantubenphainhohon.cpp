#include <bits/stdc++.h>
using namespace std;
int r1[100006],r2[1000006];
void solve1(int a[],int n,int r1[]){
    stack <int > st;
    for (int i = n- 1; i>= 0 ;i--){
        while (!st.empty() && a[i] >= a[st.top()]){
            st.pop();
        }
        if (st.empty())
        r1[i] = -1;
        else r1[i] = st.top();
        st.push(i);
    }
}   
void solve2(int a[],int n,int r2[]){
    stack <int > st;

    for (int i = n- 1; i>= 0 ;i--){
        while (!st.empty() && a[i] <= a[st.top()]){
            st.pop();
        }
        if (st.empty())
        r2[i] = -1;
        else r2[i] = a[st.top()];
        st.push(i);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n ; i++){
            cin >> a[i];
        }
        solve1(a,n,r1);
        solve2(a,n,r2);
        for (int i = 0 ; i< n ; i++){
            int tmp =r1[i];
            if (tmp == -1)
            cout <<"-1"<<" ";
            else cout << r2[tmp]<<" ";
        }
        cout << endl;
    }
    return 0;
}