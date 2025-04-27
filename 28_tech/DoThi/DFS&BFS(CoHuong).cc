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
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        cout << s << " ";
        for(int x : ke[s]){
            if(!visited[x]) {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}
void DFS(int u){
    visited[u] =  1;
    cout << u << " ";
    for(int x : ke[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        cout << "Vui Long Chon 1 (BFS) hoac 2 (DFS): ";
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            BFS(u);
            cout<<endl;
            break;
        case 2:
            DFS(u);
            cout << endl;
            break;
        default:
            cout << "Vui Long Nhap Lai!";
            break;
        }
    }
    return 0;
}