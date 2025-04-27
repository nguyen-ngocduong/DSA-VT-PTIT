#include<bits/stdc++.h>
using namespace std;
int v,e,u,t,visited[1001],parent[1001];
vector<int> ke[1001];
void init(){
    cin >> v >> e >> u >> t;
    for(int i = 0; i<1001; i++){
        visited[i] = 0;
        ke[i].clear();
        parent[i] = -1;
    }
    for(int i = 0; i<e; i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int x : ke[s]){
            if(!visited[x]){
                visited[x] = 1;
                parent[x] = s;
                q.push(x);
            }
        }
    }
}
void findPath(int s, int t){
    BFS(s);
    if(!visited[t]){
        cout << "-1" << endl;
    }
    else{
        vector<int> path;
        while(t != -1){
            path.push_back(t);
            t = parent[t];
        }
        reverse(path.begin(), path.end());
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
    }
}
int main(){
    int tc; cin >> tc;
    while(tc--){
        init();
        findPath(u,t);
    }
    return 0;
}