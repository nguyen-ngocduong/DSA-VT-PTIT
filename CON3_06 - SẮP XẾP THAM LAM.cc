#include<bits/stdc++.h>
using namespace std;
int main () {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        vector<int> v(a, a+n);
        sort(v.begin(), v.end());
        bool check = true;
        for(int i = 0; i<n; i++){
            if(a[i] != v[i] && v[i] != a[n-i-1]){
                check = false;
                cout << "No" << endl;
                break;
            }
        }
        if(check) {
            cout << "Yes" << endl;
        }
    }
    return 0;
}