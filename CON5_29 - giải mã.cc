#include<bits/stdc++.h>
using namespace std;

string s;
int solve(){
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i<=n; i++){
        //1 chu so
        if(s[i-1] != '0') {
            dp[i] += dp[i-1];
        }
        //2 chu so
        if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7'){
            dp[i] += dp[i-2];
        }
    }
    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        if(s[0] == '0'){
            cout << '0' << endl;
        }
        else {
            cout << solve() << endl;
        }
    }
    return 0;
}