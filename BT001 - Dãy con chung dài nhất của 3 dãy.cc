#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t; 
    while(t--){
        int n;
        cin>>n;
        int a[n];
    	for(int &x:a) cin>>x;
        int m; cin >> m;
        int b[m];
        for(int &x : b) cin >> x;
        int k; cin >> k;
        int c[k];
        for(int &x : c) cin >> x;
        int dp[n+1][m+1][k+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                for(int p = 0; p<=k; p++){
                    if(i == 0 || j == 0 || p == 0){
                        dp[i][j][p] = 0;
                    }
                    else if(a[i-1]==b[j-1]&&a[i-1]==c[p-1]) {
                        dp[i][j][p] = 1 + dp[i-1][j-1][p-1];
                    }
                    else{
                        dp[i][j][p] = max({dp[i-1][j][p], dp[i][j-1][p], dp[i][j][p-1]});
                    }
                }
            }
        }
        cout << dp[n][m][k] << endl;
    }
    return 0;
}