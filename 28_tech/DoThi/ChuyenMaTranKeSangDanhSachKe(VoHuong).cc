#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n+1][n+1];
        memset(a,0,sizeof(a));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                cin>> a[i][j];
                if(a[i][j] == 1) ke[i].push_back(j);
            }
        }
        for(int i = 1; i<=n;i++){
            for(int j = 0;j<ke[i].size(); j++){
                cout << ke[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}