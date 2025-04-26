#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt = 0;
        int a[n+1];
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(a[i] > a[j]) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}