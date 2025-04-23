#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        int ans = 0;
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for(int i = 0; i<n; i++){
            int tmp = a[i];
            int pos;
            int ok = 1;
            for(int j = i+1;j<n;j++){
                if(tmp > a[j]){
                    tmp = a[j];
                    pos = j;
                    ok = 0;
                }
            }
            if(ok == 0) {
                swap(a[i],a[pos]);
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}