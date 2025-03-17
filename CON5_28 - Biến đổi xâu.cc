#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main() {
    int t; cin >> t;
    while(t--){
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        int dp[105][105];
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j<=m; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<= m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}