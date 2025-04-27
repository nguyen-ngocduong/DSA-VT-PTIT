#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n+1][n+1];
        vector<pair<int,int>> canh;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(a[i][j] != 0 && i < j){ // vo huong
                    cout << i << " " << j << " " << a[i][j] << endl;
                }
            }
        }
    }
    return 0;
}