#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n;
bool comp(int a, int b){
    if(mp[a] != mp[b]) return mp[a] > mp[b];
    return a < b;
}
int main(){
    int t; cin >> t;
    while(t--){
        mp.clear();
        cin >> n;
        int a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(a, a+n, comp);
        for(int x : a){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}