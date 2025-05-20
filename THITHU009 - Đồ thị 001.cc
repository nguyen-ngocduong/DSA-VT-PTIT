#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int parent[MAXN];
int find(int u){
    if(parent[u] == u) return u; // tim goc cua u
    return find(parent[u]); // tim goc cua cha
}
int unionSet(int u, int v){
    int pu = find(u);
    int pv = find(v);
    if(pu == pv) return false;
    parent[pu] = pv;
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> edges(n);
        for(int i = 0; i<n; i++){
            cin >> edges[i].first >> edges[i].second;
        }
        // khoi tao DSU
        for(int i = 1; i<=n; i++) parent[i] = i;
        pair<int, int> res = {-1,-1};
        for(auto value : edges){
            int u = value.first, v = value.second;
            if(!unionSet(u,v)){
                res = {u,v};
            }
        }
        cout << res.first << " " << res.second;
    }
    return 0;
}