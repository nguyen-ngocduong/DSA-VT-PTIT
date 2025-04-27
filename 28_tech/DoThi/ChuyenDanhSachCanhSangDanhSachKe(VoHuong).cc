#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int main(){
    int t; cin >> t;
    while(t--){
        int v,e;
        cin >> v >> e;
        for(int i = 0; i<1001; i++) ke[i].clear();
        for(int i = 0; i<e; i++){
            int x,y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        for(int i = 1; i<=v; i++){
            sort(begin(ke[i]), end(ke[i]));
            cout << i << ": ";
            for(int x : ke[i]){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}