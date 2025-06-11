#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int n1 = s1.size(), n2 = s2.size();
        int dp[501][501];
        for(int i = 1; i<=n1; i++){
            for(int j = 1; j<=n2; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << n1 + n2 - dp[n1][n2] << endl;
    }
    return 0;
}