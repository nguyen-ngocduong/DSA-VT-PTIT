#include<bits/stdc++.h>
using namespace std;
int v, visited[1001];
vector<int> ke[1001];
void init(){
    cin >> v;
    for(int i = 0; i<1001; i++){
        visited[i] = 0;
        ke[i].clear();
    }
    for(int i = 0; i<v-1; i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void DFS(int u){
    visited[u] = 1;
    for(int x : ke[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}
void Lien_Thong(){
    for(int i = 1; i<=v; i++){
        if(visited[i] == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        DFS(1);
        if(Lien_Thong()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}