#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin >> n >> m;
        int a[n],b[m];
        int ans = 0;
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        for(int i = 0; i < n; i++){
            for(int j = 0; j<m; j++){
                if(b[j]*log(a[i] * 1.0) - a[i] * log(b[j] * 1.0) > 0) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}