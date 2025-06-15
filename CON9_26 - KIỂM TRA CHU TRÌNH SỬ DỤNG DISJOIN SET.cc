#include<bits/stdc++.h>
using namespace std;
int v,e,visited[1001], cycle;
int a[1001][1001];
void dfs(int u, int p){//u la dinh hien tai, p la dinh cha cua u
    visited[u] = 1;
    for(int i = 1; i<=v; i++){
        if(a[u][i]){// neu co canh noi giua dinh u va i
            if(!visited[i]){
                dfs(i, u);
            }
            else if(i != p){ // neu i duoc tham => ktra xem i co khac p 0
                cycle = 1;
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> v >> e;
        memset(visited,0,sizeof(visited));
        memset(a,0,sizeof(a));
        for(int i = 1; i<= e; i++){
            int x,y; cin >> x >> y;
            a[x][y] = 1;
            a[y][x] = 1;
        }
        cycle = 0;
        dfs(1,0);
        if(cycle == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}