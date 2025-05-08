#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin >> n;
        int a[n+1];
        for(int i = 0; i<n; i++) cin >> a[i];
        for(int i = 0; i<n; i++){
            int ok = 0;
            for(int j = i+1; j<n; j++){
                if(a[j] > a[i]){
                    ok = 1;
                    cout << a[j] << " ";
                    break;
                }
            }
            if(ok == 0) cout << -1 << " ";
        }
        cout << endl;
    }
    return 0;
}