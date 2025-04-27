#include<bits/stdc++.h>
using namespace std;
int v,e,u,visited[1001];
vector<int> ke[1001];
void init(){
    cin >> v >> e >> u;
    memset(visited,0,sizeof(visited));
    for(int i = 0; i<e; i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void DFS(int u){
    visited[u] = 1;
    cout << u << " ";
    for(int x : ke[u]){
        if(!visited[x]) {
            DFS(x);
        }
    }
}
int main(){
    int t;cin >> t;
    while(t--){
        init();
        DFS(u);
        cout << endl;
    }
    return 0;
}