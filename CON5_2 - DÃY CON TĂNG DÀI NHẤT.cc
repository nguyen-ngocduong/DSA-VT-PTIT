#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        vector<int> v(n,1);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(a[i] > a[j]){
                    v[i] = max(v[i], v[j] + 1);
                }
            }
        }
        cout << *max_element(v.begin(),v.end()) << endl;
    }
    return 0;
}