#include<bits/stdc++.h>
using namespace std;
int main (){
    int t; cin>>t;
    while(t--){
        int n,k; cin >> n >> k;
        map<int,int> mp;
        int a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        if(mp[k] == 0) cout << -1 << endl;
        else cout << mp[k] << endl;
    }
    return 0;
}