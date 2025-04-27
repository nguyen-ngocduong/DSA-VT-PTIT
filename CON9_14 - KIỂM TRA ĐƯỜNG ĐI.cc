#include<bits/stdc++.h>
using namespace std;
int v,e,q,s,t,visited[1001];
vector<int> ke[1001];
void init(){
    cin >> v >> e;
    for(int i = 0; i<e; i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    cin >> q;
}
void DFS(int u){
    visited[u] = 1;
    for(int x : ke[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}
bool check(int s,int t){
    memset(visited, 0, sizeof(visited));
    DFS(s);
    return visited[t];
}
int main(){
    int tc; cin >> tc;
    while(tc--){
        init();
        for(int i = 0; i < q; i++){
        	cin >> s >> t;
            if(check(s,t) == true) cout << "YES"<<endl;
        	else cout << "NO" << endl;
    	}
    }
    return 0;
}