#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int parent[10005],sz[10005];
void Init(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int Find1(int u){
    if(u == parent[u]){
        return u;
    }
   return parent[u] = Find1(parent[u]);
}
bool Union1(int u, int v){
    u = Find1(u);
    v = Find1(v);
    if(u == v) return false;
    if(sz[u] > sz[v]){
        parent[v] = u;
        sz[u] += sz[v];
    }
    else{
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}
struct canh
{
    int x,y,check;
};

int main(){
    vector<canh> C;
    cin>>n>>m>>q;
    Init();
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        C.push_back({x,y,0});
    }
    while (q--)
    {
        Init();
        int c1,u;
        cin>>c1>>u;
        c1-=1;
        C[c1].check=1;
        for(int i=0;i<C.size();i++){
            if(C[i].check==1) continue;
            Union1(C[i].x,C[i].y);
        }
        u=Find1(u);
        cout<<sz[u]<<endl;
    }
    
}