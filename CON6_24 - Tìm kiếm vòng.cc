#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[n],ans;
        for(int &x : a) cin >> x;
        for(int i = 0; i<n; i++){
            if(a[i] == k) {
                ans = i;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}