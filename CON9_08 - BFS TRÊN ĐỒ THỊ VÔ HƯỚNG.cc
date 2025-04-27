#include<bits/stdc++.h>
using namespace std;
int v,e,u,visited[1001];
vector<int> ke[1001];
void init(){
    cin >> v >> e >> u;
    memset(visited, 0, sizeof(visited));
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
    visited[u]  = 1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        cout << s << " ";
        for(int x : ke[s]) {
            if(!visited[x]) {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        BFS(u);
        cout << endl;
    }
    return 0;
}