#include<bits/stdc++.h>
using namespace std;
int v,e, visited[1001];
vector<int> ke[1001];
void init(){
    cin >> v >> e;
    for(int i = 0; i<1001; i++){
        ke[i].clear();
        visited[i] = 0;
    }
    for(int i = 0; i<e; i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        //ke[y].push_back(x);
    }
}
void solve(){
    init();
    int cnt = 0;
    for(int i = 1; i<=v; i++){
        if(ke[i].size() % 2 == 1) {
            cnt++;
        }
    }
    if(cnt == 0) cout << 1 << endl;
    else cout << 0 << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}