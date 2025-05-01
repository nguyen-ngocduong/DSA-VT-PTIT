#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >>t;
    while(t--){
        int n; cin >> n;
        int a[n+1];
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        vector<int> dp(n+1);
        dp[1] = a[1];
        for(int i = 2; i<=n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
        }
        cout << *max_element(begin(dp), end(dp)) << endl;
    }
    return 0;
}