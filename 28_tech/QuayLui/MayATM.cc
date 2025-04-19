#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for(int i = 0; i< n; i++){
            cin >> a[i];
        }
        vector<int> dp(s+1, inf);
        dp[0] = 0;
        for(int i = 0; i<n; i++){
            for(int j = s; j >= a[i]; j--){
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }
        if(dp[s] == s) cout << -1 << endl;
        else cout << dp[s] << endl;
    }
    return 0;
}