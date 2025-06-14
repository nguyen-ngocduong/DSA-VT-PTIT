#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
vector<int> ke[1001];
void main1(){ // danh sach canh
    int t; cin >> t;
    while(t--){
        for(int i = 0; i<1001; i++) ke[i].clear();
        int v,e;
        cin >> v >> e;
        for(int i = 0; i<e; i++){
            int x,y;
            cin >> x >> y; // Co canh noi giua dinh x va dinh y
            ke[x].push_back(y); // them y vao danh sach ke cua x
            ke[y].push_back(x);
        }
        for(int i = 1; i<=v; i++){
            cout << i << " : ";
            for (int x : ke[i]){
                cout << x <<  " ";
            }
            cout << endl;
        }
    }
}

void main2(){ // ma tran ke
    int n;
    cin>>n;
    int a[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]){
                adj[i].push_back(j);
            }
        }
        sort(adj[i].begin(),adj[i].end());
    }
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(int x:adj[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    main2();
}