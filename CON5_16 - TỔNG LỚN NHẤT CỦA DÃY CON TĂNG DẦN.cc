#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        vector<int> v(n);
        for(int i = 0; i<n; i++){
            v[i] = a[i];
            for(int j = 0; j<i; j++){
                if(a[i] > a[j]){
                    v[i] = max(v[i], v[j]+ a[i]);
                }
            }
        }
        cout << *max_element(begin(v), end(v)) << endl;
    }
    return 0;
}