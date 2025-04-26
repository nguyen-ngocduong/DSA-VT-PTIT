#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int v,e;
void init(){
    cin >> v >> e;
    for(int i = 0; i<1001; i++) ke[i].clear();
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        for(int i = 0; i<e;i++){
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
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