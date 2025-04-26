#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main(){
    int n; cin>>n;
    memset(a,0,sizeof(a));
    vector<int> res[1001];
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) res[i].push_back(j);
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}