#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int ans = 0, a[n];
        for(int &x : a) cin >> x;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j < n; j++){
                if(a[j] == k - a[i]){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}