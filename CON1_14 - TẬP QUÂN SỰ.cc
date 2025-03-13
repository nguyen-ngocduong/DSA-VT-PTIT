#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        int dp[100] = {0};
        for(int i = 1; i<=k; i++){
            cin >> a[i];
            dp[a[i]] = 1;
        }
        int i = k;
        while (i > 0 && a[i] == n-k+i)
        {
            i--;
        }
        if(i==0) cout << k << endl;
        else{
            a[i]++;
            for(int j = i+1; j<=k; j++){
                a[j] = a[j-1] + 1;
            }
            for(int i = 1; i<=k; i++) dp[a[i]] = 0;
            int res = 0;
            for(int i = 1; i<=n; i++){
                if(dp[i]) res++; 
            }
            cout << res << endl;
        }
    }
    return 0;
}